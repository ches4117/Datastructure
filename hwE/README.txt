This program contains three functions, DFS algorithm, Prim's algorithm, Dijkstra's algorithm.
These three functions all use adjacent matrix. DFS is easiler to do, we use a array to record
whether we have visited the vertex. If we didn't visit this vertex, then we move to this vertex.
Prim's algorithm, we find the smallest edge then add it at every loop. Dijkstra's algorithm,
we shoule record the weight of the edge, and if the cost from other vertex to the next one,
is smaller than we direct go to the target, then we updata the distance.
