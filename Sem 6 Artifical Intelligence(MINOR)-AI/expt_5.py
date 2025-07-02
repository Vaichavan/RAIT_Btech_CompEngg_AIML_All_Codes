import heapq

class AStarSearch:
    def __init__(self, graph, heuristic):
        self.graph = graph
        self.heuristic = heuristic

    def search(self, start_node, goal_node):
        open_queue = []  # Priority queue for the open set
        heapq.heappush(open_queue, (0, start_node))
        came_from = {start_node: None}
        g_costs = {start_node: 0}  # Cost from start to current node

        closed_set = set()  # Set for visited nodes

        while open_queue:
            current_cost, current_node = heapq.heappop(open_queue)

            # Check if we reached the goal
            if current_node == goal_node:
                return self.trace_path(came_from, current_node, g_costs[goal_node])

            # Skip processing if node is already visited
            if current_node in closed_set:
                continue

            closed_set.add(current_node)

            # Explore neighbors
            for neighbor, cost in self.graph.get(current_node, []):
                tentative_g_cost = g_costs[current_node] + cost

                # If this path to neighbor is better, record it
                if neighbor not in g_costs or tentative_g_cost < g_costs[neighbor]:
                    g_costs[neighbor] = tentative_g_cost
                    f_cost = tentative_g_cost + self.heuristic[neighbor]
                    heapq.heappush(open_queue, (f_cost, neighbor))
                    came_from[neighbor] = current_node

        return None  # No path found

    def trace_path(self, came_from, current_node, total_cost):
        path = []
        print("Tracing the path:")
        while current_node is not None:
            path.append(current_node)
            current_node = came_from[current_node]
        path.reverse()

        for step in path:
            print(f"-> {step}", end=" ")
        print(f"\nTotal Cost: {total_cost}")
        return path, total_cost

if __name__ == "__main__":
    # Example graph as an adjacency list with costs
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

    # Heuristic values for each node
    heuristic = {
        'S': 7, 'A': 8, 'B': 6, 'C': 5, 'D': 5, 'E': 3, 'F': 3,
        'G': 0, 'H': 7, 'I': 4, 'J': 5, 'K': 3
    }

    # A* Search Example
    astar_solver = AStarSearch(graph, heuristic)
    start_node = 'S'
    goal_node = 'G'

    print("Tracing A* Search from node A to node G:")
    result = astar_solver.search(start_node, goal_node)

