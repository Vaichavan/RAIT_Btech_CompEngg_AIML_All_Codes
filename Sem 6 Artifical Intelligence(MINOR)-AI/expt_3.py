from collections import deque

class BreadthFirstSearch:
    def __init__(self, graph):
        self.graph = graph

    def bfs(self, start_node, target_node):
        # Initialize the open queue (FIFO) and the visited dictionary
        open_queue = deque([start_node])
        visited = {start_node: None}  # Dictionary to track the path

        while open_queue:
            current_node = open_queue.popleft()

            # Check if we reached the target node
            if current_node == target_node:
                path = []
                while current_node is not None:
                    path.append(current_node)
                    current_node = visited[current_node]
                return path[::-1]

            # Add unvisited neighbors to the queue
            for neighbor in self.graph.get(current_node, []):
                if neighbor not in visited:
                    visited[neighbor] = current_node
                    open_queue.append(neighbor)
        
        return None  # Return None if no path is found

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

    # Trace BFS for example
    bfs_solver = BreadthFirstSearch(graph)
    start_node = 'S'
    target_node = 'J'

    print("Tracing BFS from node S to node J:")
    result = bfs_solver.bfs(start_node, target_node)
    if result:
        print("Path:", " -> ".join(result))
    else:
        print("No path found.")
