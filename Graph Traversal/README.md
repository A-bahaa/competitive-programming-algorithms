# Content

- [DFS](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/DFS.cpp)
- [BFS](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Graph%20Traversal/BFS.cpp)


## DFS

![4b2bba0](https://user-images.githubusercontent.com/65967989/140500100-8625a116-0ca6-48aa-a918-010925d69c37.jpg)

## BFS

![b80dcfa](https://user-images.githubusercontent.com/65967989/140500167-e09747db-98e7-45ea-aa82-3c24f99828d5.jpg)



## Applications

### Connectivity Check

A graph is connected if there's a path between any two nodes of the graph . Thus, we can just select an arbitrary node and run the traversing search from it and finding out if we can reach all the other nodes . In a similar way, we can find all connected components of a graph by iterating through the nodes and always starting a new DFS (BFS) if the current node doesn't belong to any component yet .
