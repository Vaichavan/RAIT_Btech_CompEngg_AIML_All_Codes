
#############     Experiment 2- Water Jug     ################

from collections import deque

class WaterJugs:
    def __init__(self):
        self.a_max = 4
        self.b_max = 3
        self.target = 2

    def goal_reached(self, jugs):
        return jugs[0] == self.target

    def next_moves(self, jugs):
        a, b = jugs
        return [
            (self.a_max, b),
            (a, self.b_max),
            (0, b),
            (a, 0),
            (a - min(a, self.b_max - b), b + min(a, self.b_max - b)),
            (a + min(b, self.a_max - a), b - min(b, self.a_max - a))
        ]

    def solve(self):
        start = (0, 0)
        q = deque([(start, [start])])
        seen = set()

        while q:
            state, trace = q.popleft()

            if self.goal_reached(state):
                return trace

            if state in seen:
                continue

            seen.add(state)

            for nxt in self.next_moves(state):
                if nxt not in seen:
                    q.append((nxt, trace + [nxt]))

        return None

if __name__ == "__main__":
    wj = WaterJugs()
    result = wj.solve()

    if result:
        print("Shortest Solution Path (6 Steps):")
        for s in result:
            print(f"Jug A: {s[0]} liters, Jug B: {s[1]} liters")
    else:
        print("No solution found.")


#############     Experiment 3- BFS    ################


from collections import deque

class BFS:
    def __init__(self, edges):
        self.edges = edges

    def run(self, start, goal):
        queue = deque([start])
        came_from = {start: None}

        while queue:
            node = queue.popleft()

            if node == goal:
                route = []
                while node is not None:
                    route.append(node)
                    node = came_from[node]
                return route[::-1]

            for adj in self.edges.get(node, []):
                if adj not in came_from:
                    came_from[adj] = node
                    queue.append(adj)

        return None

if __name__ == "__main__":
    net = {
        'S': ['A', 'B', 'C'],
        'A': ['D'],
        'B': ['E'],
        'C': ['F', 'J'],
        'D': ['G'],
        'G': ['J'],
    }

    search = BFS(net)
    start = 'S'
    end = 'J'

    print("Tracing BFS from node S to node J:")
    result = search.run(start, end)
    if result:
        print("Path:", " -> ".join(result))
    else:
        print("No path found.")


#############     Experiment 4- DFS     ################

class DFS:
    def __init__(self, edges):
        self.edges = edges

    def search(self, current, goal, route=None):
        if route is None:
            route = []

        route.append(current)

        if current == goal:
            return route

        for adj in self.edges.get(current, []):
            if adj not in route:
                found = self.search(adj, goal, route)
                if found:
                    return found

        route.pop()
        return None

if __name__ == "__main__":
    net = {
        'S': ['A', 'B', 'C'],
        'A': ['D'],
        'B': ['E'],
        'C': ['F', 'J'],
        'D': ['G'],
        'G': ['J'],
    }

    dfs = DFS(net)
    start = 'S'
    end = 'J'

    print("Tracing DFS from node S to node J:")
    result = dfs.search(start, end)
    if result:
        print("Path:", " -> ".join(result))
    else:
        print("No path found.")


#############     Experiment 5- A-star algo     ################

import heapq

class AStar:
    def __init__(self, edges, estimate):
        self.edges = edges
        self.estimate = estimate

    def find(self, source, target):
        queue = []
        heapq.heappush(queue, (0, source))
        route = {source: None}
        cost_so_far = {source: 0}
        seen = set()

        while queue:
            _, node = heapq.heappop(queue)

            if node == target:
                return self.build_path(route, node, cost_so_far[target])

            if node in seen:
                continue

            seen.add(node)

            for adj, weight in self.edges.get(node, []):
                new_cost = cost_so_far[node] + weight

                if adj not in cost_so_far or new_cost < cost_so_far[adj]:
                    cost_so_far[adj] = new_cost
                    priority = new_cost + self.estimate[adj]
                    heapq.heappush(queue, (priority, adj))
                    route[adj] = node

        return None

    def build_path(self, route, node, total):
        path = []
        print("Tracing the path:")
        while node is not None:
            path.append(node)
            node = route[node]
        path.reverse()

        for step in path:
            print(f"-> {step}", end=" ")
        print(f"\nTotal Cost: {total}")
        return path, total

if __name__ == "__main__":
    graph = {
        'S': [('A', 4), ('B', 10), ('C', 11)],
        'A': [('B', 8), ('D', 5)],
        'B': [('D', 15)],
        'C': [('D', 8), ('E', 20), ('F', 2)],
        'D': [('F', 1), ('I', 20), ('H', 16)],
        'E': [('G', 19)],
        'F': [('G', 13)],
        'H': [('J', 2), ('I', 1)],
        'I': [('K', 13), ('G', 5), ('J', 5)],
        'J': [('K', 7)],
        'K': [('G', 16)]
    }

    h = {
        'S': 7, 'A': 8, 'B': 6, 'C': 5, 'D': 5, 'E': 3, 'F': 3,
        'G': 0, 'H': 7, 'I': 4, 'J': 5, 'K': 3
    }

    search = AStar(graph, h)
    start = 'S'
    end = 'G'

    print("Tracing A* Search from node S to node G:")
    result = search.find(start, end)

#############     Experiment 6- PROLOG     ################

#COMMANDS
# pwd.
#put file there
# [file_name]. 
# parent(X,Y).
# grandparent(X,ralph).
# ancestor(X,anne).
# ancestor(meg, ralph).
# weather(phenoi_x, summer, X).

#======================================================

% Weather facts
weather(phenoi_x, summer, hot).
weather(a1, summer, warm).
weather(phenoi_x, winter, warm).

% Family relationships
parent(joe, jane).
parent(harry, carl).
parent(meg, jane).
parent(jane, anne).
parent(carl, ralph).
parent(hazel, harry).

% Grandparent rule
grandparent(X, Z) :-
    parent(X, Y),
    parent(Y, Z).

% Base case: X is a direct parent of Y
ancestor(X, Y) :- parent(X, Y).

% Recursive case: X is an ancestor of Y if X is a parent of Z, and Z is an ancestor of Y
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).

#############     Experiment 7- FOC     ################

!pip install aima3 # Install the aima3 library

from aima3.logic import FolKB, expr, fol_fc_ask

def run():
    facts = [
        expr("(American(x) & Weapon(y) & Sells(x, y, z) & Hostile(z)) ==> Criminal(x)"),
        expr("Enemy(Nono, America)"),
        expr("Owns(Nono, M1)"),
        expr("Missile(M1)"),
        expr("(Missile(x) & Owns(Nono, x)) ==> Sells(West, x, Nono)"),
        expr("American(West)"),
        expr("Missile(x) ==> Weapon(x)")
    ]

    kb = FolKB(facts)

    kb.tell(expr("Enemy(Coco, America)"))
    kb.tell(expr("Enemy(Jojo, America)"))
    kb.tell(expr("Enemy(x, America) ==> Hostile(x)"))

    hostile = list(fol_fc_ask(kb, expr("Hostile(x)")))
    criminal = list(fol_fc_ask(kb, expr("Criminal(x)")))

    if hostile:
        print("Hostile? YES")
        print("Entities:", hostile)
    else:
        print("Hostile? NO")

    if criminal:
        print("Criminal? YES")
        print("Entities:", criminal)
    else:
        print("Criminal? NO")

if __name__ == "__main__":
    run()

#############     Experiment 8- Fuzzy Operations     ################
import numpy as np
import matplotlib.pyplot as plt

def triangle(x, points):
    a, b, c = points
    return np.maximum(np.minimum((x - a) / (b - a), (c - x) / (c - b)), 0)

def neg(x):
    return 1 - x

def fuzzy_or(a, b):
    return np.maximum(a, b)

def fuzzy_and(a, b):
    return np.minimum(a, b)

if __name__ == "__main__":
    x_vals = np.linspace(0, 75, 75)

    set1 = triangle(x_vals, [0, 25, 50])
    set2 = triangle(x_vals, [25, 50, 75])

    union = fuzzy_or(set1, set2)
    intersect = fuzzy_and(set1, set2)
    not_a = neg(set1)
    diff = fuzzy_and(set1, neg(set2))
    alg_sum = set1 + set2 - (set1 * set2)
    alg_prod = set1 * set2
    bdd_sum = np.minimum(1, set1 + set2)
    bdd_diff = np.maximum(0, set1 - set2)

    results = [
        (set1, "Young"),
        (set2, "Middle Aged"),
        (union, "Union"),
        (intersect, "Intersection"),
        (not_a, "NOT Young"),
        (diff, "Young \\ Middle Aged"),
        (alg_sum, "Algebraic Sum"),
        (alg_prod, "Algebraic Product"),
        (bdd_sum, "Bounded Sum"),
        (bdd_diff, "Bounded Difference")
    ]

    plt.figure(figsize=(12, 8))
    for idx, (curve, label) in enumerate(results, 1):
        plt.subplot(4, 3, idx)
        plt.plot(x_vals, curve)
        plt.title(label)
        plt.grid(True)

    plt.tight_layout()
    plt.show()

#############     Experiment 9- Fuzzy Operations     ################
import numpy as np
import skfuzzy as fuzz # type: ignore
import matplotlib.pyplot as plt

x_food = x_service = np.arange(0, 11, 1)
x_tip = np.arange(0, 26, 1)

def triangle(x, params):
    return fuzz.trimf(x, params)

food_bad = triangle(x_food, [0, 0, 5])
food_ok = triangle(x_food, [0, 5, 10])
food_good = triangle(x_food, [5, 10, 10])

serv_poor = triangle(x_service, [0, 0, 5])
serv_avg = triangle(x_service, [0, 5, 10])
serv_great = triangle(x_service, [5, 10, 10])

tip_low = triangle(x_tip, [0, 0, 13])
tip_mid = triangle(x_tip, [0, 13, 25])
tip_high = triangle(x_tip, [13, 25, 25])

def draw_mf(x, sets, labels, title):
    fig, ax = plt.subplots(figsize=(8, 3))
    for s, l, c in zip(sets, labels, ['b', 'g', 'r']):
        ax.plot(x, s, c, linewidth=1.5, label=l)
    ax.set_title(title)
    ax.legend()
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    plt.tight_layout()

draw_mf(x_food, [food_bad, food_ok, food_good], ['Bad', 'Decent', 'Great'], 'Food')
draw_mf(x_service, [serv_poor, serv_avg, serv_great], ['Poor', 'Acceptable', 'Amazing'], 'Service')
draw_mf(x_tip, [tip_low, tip_mid, tip_high], ['Low', 'Medium', 'High'], 'Tip')

food_val = 6.5
serv_val = 9.8

food_levels = [fuzz.interp_membership(x_food, f, food_val) for f in [food_bad, food_ok, food_good]]
serv_levels = [fuzz.interp_membership(x_service, s, serv_val) for s in [serv_poor, serv_avg, serv_great]]

r1 = np.fmax(food_levels[0], serv_levels[0])
act_low = np.fmin(r1, tip_low)

r2 = serv_levels[1]
act_mid = np.fmin(r2, tip_mid)

r3 = np.fmax(food_levels[2], serv_levels[2])
act_high = np.fmin(r3, tip_high)

def draw_activation(x, acts, labels, title):
    fig, ax = plt.subplots(figsize=(8, 3))
    shapes = {'Low': tip_low, 'Medium': tip_mid, 'High': tip_high}
    for act, lbl, col in zip(acts, labels, ['b', 'g', 'r']):
        ax.fill_between(x, 0, act, facecolor=col, alpha=0.7)
        ax.plot(x, shapes[lbl], col, linewidth=0.5, linestyle='--')
    ax.set_title(title)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    plt.tight_layout()

draw_activation(x_tip, [act_low, act_mid, act_high], ['Low', 'Medium', 'High'], 'Tip Activation')

combined = np.fmax(act_low, np.fmax(act_mid, act_high))
final_tip = fuzz.defuzz(x_tip, combined, 'centroid')
tip_level = fuzz.interp_membership(x_tip, combined, final_tip)

fig, ax = plt.subplots(figsize=(8, 3))
ax.plot(x_tip, tip_low, 'b', linewidth=0.5, linestyle='--')
ax.plot(x_tip, tip_mid, 'g', linewidth=0.5, linestyle='--')
ax.plot(x_tip, tip_high, 'r', linewidth=0.5, linestyle='--')
ax.fill_between(x_tip, 0, combined, facecolor='orange', alpha=0.7)
ax.plot([final_tip, final_tip], [0, tip_level], 'k', linewidth=1.5, alpha=0.9)
ax.set_title(f'Tip = {final_tip:.2f}%')
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
plt.tight_layout()

plt.show()
