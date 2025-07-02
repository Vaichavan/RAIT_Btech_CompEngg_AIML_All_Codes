from collections import deque

class JugProblemBFS:
    def __init__(self):
        self.capacity_a = 4  # Capacity of Jug A
        self.capacity_b = 3  # Capacity of Jug B
        self.target = 2      # Target amount in Jug A

    def is_goal(self, state):
        return state[0] == self.target

    def get_next_states(self, state):
        a, b = state
        return [
            (self.capacity_a, b),               # Fill Jug A
            (a, self.capacity_b),               # Fill Jug B
            (0, b),                             # Empty Jug A
            (a, 0),                             # Empty Jug B
            (a - min(a, self.capacity_b - b), b + min(a, self.capacity_b - b)),  # Pour A to B
            (a + min(b, self.capacity_a - a), b - min(b, self.capacity_a - a))   # Pour B to A
        ]

    def bfs(self):
        initial_state = (0, 0)
        queue = deque([(initial_state, [initial_state])])
        visited = set()

        while queue:
            (current_state, path) = queue.popleft()

            if self.is_goal(current_state):
                return path

            if current_state in visited:
                continue

            visited.add(current_state)

            for next_state in self.get_next_states(current_state):
                if next_state not in visited:
                    queue.append((next_state, path + [next_state]))
        
        return None

if __name__ == "__main__":
    problem = JugProblemBFS()
    solution = problem.bfs()

    if solution:
        print("Shortest Solution Path (6 Steps):")
        for step in solution:
            print(f"Jug A: {step[0]} liters, Jug B: {step[1]} liters")
    else:
        print("No solution found.")
