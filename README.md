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

**Time complexity** `O(ELogV)`  .. Time complexity can be reduced to `O(E + VLogV)` using Fibonacci Heap .

**What if all the edges have the same weight ?** you still could use dijkstra but for this special case you might consider using BFS  ` O(V+E)` because it's faster than dijkstra  `O(E + VLogV)` . And the reason BFS would work is that in this special case there's no choice to make regarding the edge weight , they're all equal so the problem transformed to be "How many levels is the target node from the source node ?" which is achievable using BFS .

**If we run Dijkstra without a target node** , we'll get a SPT (shortest path tree) which root is the source node and connects all the nodes in the graph with the minimum cost starting from the source .

**can we consider the resulting SPT as an MST?** NO, because both SPT and MST try to achieve different goals . SPT holds the minimum cost to get to each node in the graph **starting from the source** .. On the other side , MST holds minimum cost to connect all the nodes together .. For example , the green tree is a SPT starting from _v1_ while the yellow tree is the MST of the graph .. The total cost to conect all the green nodes is 39 which is higher than the MST with a 22 total cost .. but what about the cost to go from _v1_ to _v8_ ? .. the SPT spends 21 which is lower than what MST spends (22) , so that illustrate that both try to achieve different goals hence make different compromises .. MST compromises on making the distance between two nodes the minimum to priotize making the total cost as minnimum as possible .. SPT is forced to start from a particular node , so it compromises on chosing the edges to priotize taking the shortest route to each node . 
MST            |  SPT
:-------------------------:|:-------------------------:
![dmst3](https://user-images.githubusercontent.com/65967989/134606495-be36b394-43c4-4e1c-96c3-dc6b4fe2eb8b.jpg)  |  ![dmst1](https://user-images.githubusercontent.com/65967989/134606503-e82f867f-c141-40a4-b6c3-2046435415c6.jpg)



 



