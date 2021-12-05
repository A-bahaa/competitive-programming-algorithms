# Content

- [DFS](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/DFS.cpp)
- [BFS](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/BFS.cpp)
- [directedAcyclic](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/directedAcyclic.cpp)
- [undirectedAcyclic](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/udirectedAcyclic.cpp)
- [Bipartiteness check](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/Bipartite.cpp)
- [Topological Sort](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/topSort.cpp)
- [Tree Minimum Traverse](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/minForest.cpp)
- [Notes]()


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

### Topological Sort
![d6be27e](https://user-images.githubusercontent.com/65967989/141207081-13c511bf-8ce5-4b94-b655-b8e7682b3abb.png)

Topological sorting of vertices of a **Directed Acyclic Graph** is an ordering of the vertices `v1` , `v2` , ... `vn` in such a way, that if there is an edge directed towards vertex `vj`  from vertex `vi` , then `vi` comes before `vj` . For example consider the graph given upove:

A topological sorting of this graph is:   1 2 3 4 5 .  
There are multiple topological sorting possible for a graph. For the graph given above one another topological sorting is:  1 2 3 5 4 .

By definition, all rooted trees have a topological ordering since they don't contain any cycles .  

#### Resources
- https://www.youtube.com/watch?v=ddTC4Zovtbc&t=1s

### Tree minimum traverse
![Inkedgo1_LI](https://user-images.githubusercontent.com/65967989/141689459-3625e7db-f12e-4ca7-856a-0080f35b60c5.jpg)

If you need to traverse all leaves in a rooted tree with `E` edges starting from the root and ending in this root then it will cost you `2⋅E` (it doesn't depend on the traversal you choose, right?). If you stop at some leaf `n` because you've already visited all other leaves then it'll cost you `2⋅E−cost(n)`. So, to minimize the cost you need to choose your traversal to stop at the leaf n with maximal cost(n).

## Notes
