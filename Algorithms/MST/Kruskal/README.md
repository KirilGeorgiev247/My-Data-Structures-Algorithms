# Kruskal

Method used in graph theory to find a minimum spanning tree for a connected, undirected graph. It finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized. 

***

+ Sort the edges: start by sorting all the edges of the graph in non-decreasing order of their weight.

+ Initialization: create a forest (a set of trees), where each vertex in the graph is a separate tree.

+ Edge selection: go through the sorted edges and iterate over them one by one. For each edge, check if the ends of the edge belong to different trees. If they do, add this edge to the forest, connecting the two trees.

+ Checking for cycles: when considering each edge, ensure that adding the edge to the forest does not create a cycle. If the addition of an edge creates a cycle, then discard this edge.

+ Union: when an edge is added to the forest, merge the two trees that the edge connects into a single tree. This is typically done using a union-find data structure for efficiency.

+ Repeat the process: repeat steps 3 to 5 until all vertices are contained in a single tree or all edges have been checked.

+ Completion: the algorithm finishes when there is a single tree left in the forest. This tree is the minimum spanning tree of the graph.
