import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm

def trimf(x, abc):
    """ Triangular membership function """
    a, b, c = abc
    return np.maximum(np.minimum((x - a) / (b - a), (c - x) / (c - b)), 0)

def fuzzy_not(A):
    return 1 - A

def fuzzy_or(A, B):
    return np.maximum(A, B)

def fuzzy_and(A, B):
    return np.minimum(A, B)

if __name__ == "__main__":
    # Create universe of discourse
    X = np.linspace(0, 75, 75)
    
    # Create fuzzy sets
    abc1 = [0, 25, 50]
    abc2 = [25, 50, 75]
    young = trimf(X, abc1)
    middle_aged = trimf(X, abc2)
    
    # Compute fuzzy operations
    union = fuzzy_or(young, middle_aged)
    intersection = fuzzy_and(young, middle_aged)
    complement_a = fuzzy_not(young)
    difference = fuzzy_and(young, fuzzy_not(middle_aged))
    alg_sum = young + middle_aged - (young * middle_aged)
    alg_product = young * middle_aged
    bdd_sum = np.minimum(1, young + middle_aged)
    bdd_difference = np.maximum(0, young - middle_aged)
    
    # Plot results
    plt.figure(figsize=(12, 8))
    plots = [
        (young, "Young"), (middle_aged, "Middle Aged"),
        (union, "Union"), (intersection, "Intersection"),
        (complement_a, "Complement A"), (difference, "Difference A/B"),
        (alg_sum, "Algebraic Sum"), (alg_product, "Algebraic Product"),
        (bdd_sum, "Bounded Sum"), (bdd_difference, "Bounded Difference")
    ]
    
    for i, (data, title) in enumerate(plots, 1):
        plt.subplot(4, 3, i)
        plt.plot(X, data)
        plt.title(title)
        plt.grid(True)
    
    plt.subplots_adjust(hspace=0.5)
    plt.show()
