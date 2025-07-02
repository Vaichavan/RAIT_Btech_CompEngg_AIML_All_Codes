from heapq import heappop, heappush

def a_star_search(graph: dict, start: str, goal: str, heuristic_values: dict):
    open_list = [(heuristic_values[start], start)]
    closed_list = set()
    came_from = {}  # Dictionary to store the path

    g_score = {node: float('inf') for node in graph}
    g_score[start] = 0

    while open_list:
        cost, node = heappop(open_list)

        if node == goal:
            path = reconstruct_path(came_from, start, goal)
            print("Shortest Path:", " -> ".join(path))
            return cost  # Return the total cost

        if node in closed_list:
            continue

        closed_list.add(node)

        cost -= heuristic_values[node]

        for neighbor, edge_cost in graph.get(node, []):
            if neighbor in closed_list:
                continue

            tentative_g_score = g_score[node] + edge_cost
            if tentative_g_score < g_score[neighbor]:
                g_score[neighbor] = tentative_g_score
                f_score = tentative_g_score + heuristic_values[neighbor]
                heappush(open_list, (f_score, neighbor))
                came_from[neighbor] = node

    return -1  # No path found

def reconstruct_path(came_from, start, goal):
    path = []
    node = goal
    while node != start:
        path.append(node)
        node = came_from.get(node)
        if node is None:
            return []  # No valid path found
    path.append(start)
    path.reverse()
    return path

EXAMPLE_GRAPH = {
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

EXAMPLE_HEURISTIC_VALUES = {
    'S': 7, 'A': 8, 'B': 6, 'C': 5, 'D': 5, 'E': 3, 'F': 3,
    'G': 0, 'H': 7, 'I': 4, 'J': 5, 'K': 3
}

EXAMPLE_RESULT = a_star_search(EXAMPLE_GRAPH, 'S', 'G', EXAMPLE_HEURISTIC_VALUES)
print("Total Cost:", EXAMPLE_RESULT)
