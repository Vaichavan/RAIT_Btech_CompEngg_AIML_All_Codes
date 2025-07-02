class DepthFirstSearch:
    def __init__(self, graph):
        self.graph = graph

    def dfs_recursive(self, node, target_node, path=None):
        if path is None:
            path = []

        path.append(node)

        # Check if we reached the target node
        if node == target_node:
            return path

        # Explore neighbors recursively
        for neighbor in self.graph.get(node, []):
            if neighbor not in path:
                result = self.dfs_recursive(neighbor, target_node, path)
                if result:
                    return result

        path.pop()  # Backtrack if the target is not found
        return None

if __name__ == "__main__":
    # Example graph as an adjacency list
    graph = {
        'S': ['A', 'B', 'C'],
        'A': ['D'],
        'B': ['E'],
        'C': ['F', 'J'],
        'D': ['G'],
        'G': ['J'],
    }

    # Trace DFS for example
    dfs_solver = DepthFirstSearch(graph)
    start_node = 'S'
    target_node = 'J'

    print("Tracing DFS from node S to node J:")
    result = dfs_solver.dfs_recursive(start_node, target_node)
    if result:
        print("Path:", " -> ".join(result))
    else:
        print("No path found.")
