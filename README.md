# competitive-programming-algorithms
Documenting the Algorithms and techniques I learn for competitive programming contests .

## content

 - [Graph theory]
 - [DFS](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/dfs_bfs.cpp)
 - [BFS](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/dfs_bfs.cpp)
 - [Union-Find Disjoint Sets](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/dsu.cpp)
 - [MST](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/mst.cpp)
 - [Dijkstra](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/dijkstra.cpp)

## Discussion

 ### Graph theory
 ### DFS
 ### BFS
 ### Union-Find Disjoint Sets
 ### MST
 ### Dijkstra
![Dijkstra_Animation](https://user-images.githubusercontent.com/65967989/134578768-b95584ae-7caa-407c-be7c-95deb210c461.gif)

**Time complexity** O(ELogV)  .. Time complexity can be reduced to `O(E + VLogV)` using Fibonacci Heap .

**What if all the edges have the same weight ?** you still could use dijkstra but for this special case you might consider using BFS  ` O(V+E)` because it's faster than dijkstra  `O(E + VLogV)` . And the reason BFS would work is that in this special case there's no choice to make regarding the edge weight , they're all equal so the problem transformed to be "How many levels is the target node from the source node ?" which is achievable using BFS .


