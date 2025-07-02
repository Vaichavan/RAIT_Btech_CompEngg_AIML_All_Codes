import numpy as np
import skfuzzy as fuzz
import matplotlib.pyplot as plt

# Define universes
x_qual = x_serv = np.arange(0, 11, 1)
x_tip = np.arange(0, 26, 1)

# Helper function for triangular membership
def trimf(var, params):
    return fuzz.trimf(var, params)

# Generate fuzzy membership functions
qual_lo = trimf(x_qual, [0, 0, 5])  # Bad food
qual_md = trimf(x_qual, [0, 5, 10]) # Decent food
qual_hi = trimf(x_qual, [5, 10, 10]) # Great food

serv_lo = trimf(x_serv, [0, 0, 5])  # Poor service
serv_md = trimf(x_serv, [0, 5, 10]) # Acceptable service
serv_hi = trimf(x_serv, [5, 10, 10]) # Amazing service

tip_lo = trimf(x_tip, [0, 0, 13])   # Low tip
tip_md = trimf(x_tip, [0, 13, 25])  # Medium tip
tip_hi = trimf(x_tip, [13, 25, 25]) # High tip

# Plot membership functions
def plot_membership(var, funcs, labels, title):
    fig, ax = plt.subplots(figsize=(8, 3))
    colors = ['b', 'g', 'r']
    for func, label, color in zip(funcs, labels, colors):
        ax.plot(var, func, color, linewidth=1.5, label=label)
    ax.set_title(title)
    ax.legend()
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    plt.tight_layout()

plot_membership(x_qual, [qual_lo, qual_md, qual_hi], ['Bad', 'Decent', 'Great'], 'Food quality')
plot_membership(x_serv, [serv_lo, serv_md, serv_hi], ['Poor', 'Acceptable', 'Amazing'], 'Service quality')
plot_membership(x_tip, [tip_lo, tip_md, tip_hi], ['Low', 'Medium', 'High'], 'Tip amount')

# Input values (food=6.5, service=9.8)
qual_levels = [fuzz.interp_membership(x_qual, qual, 6.5) for qual in [qual_lo, qual_md, qual_hi]]
serv_levels = [fuzz.interp_membership(x_serv, serv, 9.8) for serv in [serv_lo, serv_md, serv_hi]]

# Apply fuzzy rules
rule1 = np.fmax(qual_levels[0], serv_levels[0])  # Bad food OR poor service → Low tip
tip_activation_lo = np.fmin(rule1, tip_lo)

rule2 = serv_levels[1]  # Acceptable service → Medium tip
tip_activation_md = np.fmin(rule2, tip_md)

rule3 = np.fmax(qual_levels[2], serv_levels[2])  # Great food OR amazing service → High tip
tip_activation_hi = np.fmin(rule3, tip_hi)

# Plot rule activations
def plot_activation(x, activations, labels, title):
    fig, ax = plt.subplots(figsize=(8, 3))
    colors = ['b', 'g', 'r']
    # Map labels to correct membership functions
    membership_funcs = {
        'Low': tip_lo,
        'Medium': tip_md,
        'High': tip_hi
    }
    for activation, label, color in zip(activations, labels, colors):
        ax.fill_between(x, np.zeros_like(x), activation, facecolor=color, alpha=0.7)
        ax.plot(x, membership_funcs[label], color, linewidth=0.5, linestyle='--')
    ax.set_title(title)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    plt.tight_layout()

plot_activation(x_tip, [tip_activation_lo, tip_activation_md, tip_activation_hi], ['Low', 'Medium', 'High'], 'Output membership activity')

# Aggregate and defuzzify
aggregated = np.fmax(tip_activation_lo, np.fmax(tip_activation_md, tip_activation_hi))
tip = fuzz.defuzz(x_tip, aggregated, 'centroid')  # Calculate centroid
tip_activation = fuzz.interp_membership(x_tip, aggregated, tip)  # Membership at tip value

# Plot aggregated result
fig, ax = plt.subplots(figsize=(8, 3))
ax.plot(x_tip, tip_lo, 'b', linewidth=0.5, linestyle='--')
ax.plot(x_tip, tip_md, 'g', linewidth=0.5, linestyle='--')
ax.plot(x_tip, tip_hi, 'r', linewidth=0.5, linestyle='--')
ax.fill_between(x_tip, np.zeros_like(x_tip), aggregated, facecolor='Orange', alpha=0.7)
ax.plot([tip, tip], [0, tip_activation], 'k', linewidth=1.5, alpha=0.9)
ax.set_title(f'Aggregated membership and result (tip = {tip:.2f}%)')
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
plt.tight_layout()

# Show all plots
plt.show()