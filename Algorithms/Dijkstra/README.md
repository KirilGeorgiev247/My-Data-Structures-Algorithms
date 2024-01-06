# Dijkstra

Dijkstra's algorithm is a well-known computational procedure used to find the shortest paths between nodes in a graph, which may represent, for example, road networks

+ Mark all nodes unvisited. Create a set of all the unvisited nodes called the unvisited set. Assign to every node a tentative distance value: set it to zero for the initial node and to infinity for all other nodes (1)

+ Set the initial node as current (2)

+ For the current node, consider all of its unvisited neighbors (3)

+ After considering all neighbors of the current node, mark the current node as visited (4)

+ If the destination node has been marked visited or the smallest tentative distance among the nodes in the unvisited set is infinity (occurs when there is no connection between the initial node and remaining unvisited nodes), then stop (5)

+ Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new current node, and go back to step 3 (6)