# Content

- [DFS](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/DFS.cpp)
- [BFS](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/BFS.cpp)
- [directedAcyclic](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/directedAcyclic.cpp)
- [undirectedAcyclic](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/udirectedAcyclic.cpp)
- [Bipartiteness check](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/Bipartite.cpp)


## DFS

![4b2bba0](https://user-images.githubusercontent.com/65967989/140500100-8625a116-0ca6-48aa-a918-010925d69c37.jpg)

## BFS

![b80dcfa](https://user-images.githubusercontent.com/65967989/140500167-e09747db-98e7-45ea-aa82-3c24f99828d5.jpg)



## Applications

### Connectivity Check

A graph is connected if there's a path between any two nodes of the graph . Thus, we can just select an arbitrary node and run the traversing search from it and finding out if we can reach all the other nodes . In a similar way, we can find all connected components of an undirected graph by iterating through the nodes and always starting a new DFS (BFS) if the current node doesn't belong to any component yet .

For directed graphs there is the notion of strongly connected components, for which multiple algorithms are available, all slightly more complicated than a simple DFS.

### Cycle Detection

The technique for cycle detection differs upon the type of the graph whether being directed or undirected . That's because by defintion any edge in an undirected graph is a cycle by itself so we can't use the same algo for both .

Another way to find out whether a graph contains a cycle or not is to simply calculate the number of nodes and edges in each component . If a component contains `c` nodes and no cycle, it must contains exactly `c-1` edges (so it has to be a tree) . If there are more edges , the component surly contains a cycle . 

#### Resources
- https://www.youtube.com/watch?v=n_t0a_8H8VY

### Bipartiteness check
![BipartiteGraph_1000](https://user-images.githubusercontent.com/65967989/141159210-d2dc597d-3a59-479a-a5d1-047b1265c5d3.gif)

A bipartite graph is a graph whose vertices can be divided into two disjoint sets so that every edge connects two vertices from different sets (i.e. there are no edges which connect vertices from the same set). These sets are usually called sides.

#### Assumptions
- The graph is undirected.
- The graph contains no self-loops.

There exists a theorem which claims that a graph is bipartite if and only if all its cycles have even length. However, in practice it's more convenient to use a different formulation of the definition: a graph is bipartite if and only if it is two-colorable.
