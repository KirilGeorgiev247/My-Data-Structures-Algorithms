# Prim

The Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.

***

+ Initialize all vertices as not being included in the MST yet (1)

+ Set the weight of the edge to each node as infinite, except for the start node (chosen to be node 0 in this implementation), which is set to 0 (2)

+ Use a priority queue (binary heap) to select the edge with the smallest weight that connects a vertex in the MST to a vertex outside the MST (3)

+ Pop the edge from the priority queue (binary heap), and if the connected vertex is not already included in the MST, mark it as included (4)

+ Update the priority queue (binary heap) with new edges connected to the newly included vertex if they offer a smaller weight than the current known edges (5)

+ Repeat steps 3-5 until the priority queue is empty, meaning all vertices have been included in the MST (6)

+ Collect all the edges that have been included in the MST and return them (7)