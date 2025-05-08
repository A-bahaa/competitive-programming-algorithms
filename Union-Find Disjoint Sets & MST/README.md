# Content
- [DSU Intro by techiedelight](https://github.com/A-bahaa/competitive-programming-algorithms/tree/main/Union-Find%20Disjoint%20Sets%20%26%20MST#dsu-intro)
- [MST intro by hackerearth](https://github.com/A-bahaa/competitive-programming-algorithms/tree/main/Union-Find%20Disjoint%20Sets%20%26%20MST#mst-intro)
- [Good problems](https://github.com/A-bahaa/competitive-programming-algorithms/tree/main/Union-Find%20Disjoint%20Sets%20%26%20MST#good-problems)




## DSU Intro
**Problem:** We have some number of items. We are allowed to merge any two items to consider them equal. At any point, we are allowed to ask whether two items are considered equal or not.

A disjoint–set is a data structure that keeps track of a set of elements partitioned into several disjoint (non-overlapping) subsets. In other words, a disjoint set is a group of sets where no item can be in more than one set. It is also called a union–find data structure as it supports union and find operation on subsets. Let’s begin by defining them:

Find: It determines in which subset a particular element is in and returns the representative of that particular set. An item from this set typically acts as a “representative” of the set.

Union: It merges two different subsets into a single subset, and the representative of one set becomes representative of another.


**Time Complexity of Union-Find Operations in Disjoint Set Union (DSU)**
The time complexity of the union and find operations in a Disjoint Set Union (DSU) data structure, also known as a Union-Find data structure, is a crucial aspect of its efficiency. This complexity varies significantly based on the specific implementation and optimizations employed.

**Without Optimizations:**

In a naive implementation without any optimizations, both the union and find operations can have a worst-case time complexity of O(n), where n is the number of elements. This occurs when the tree-like structures representing the sets become skewed, essentially forming a linked list. In such scenarios, a find operation might need to traverse all n elements to reach the representative (root), and a union operation, which typically involves two find operations, would consequently also take O(n).

**With Optimizations: Path Compression and Union by Rank/Size**

To significantly improve performance, two primary optimizations are commonly used:

**Path Compression:** During a find operation, this technique makes every node on the path from the queried element to the root point directly to the root. This flattens the tree structure, speeding up future find operations for elements in that path and their descendants.

**Union by Rank or Union by Size:**

Union by Rank: This heuristic always attaches the shorter tree to the root of the taller tree during a union operation. The "rank" is an upper bound on the height of a tree.
Union by Size: This heuristic always attaches the tree with fewer elements to the root of the tree with more elements during a union operation.
When both path compression and union by rank (or union by size) are implemented, the amortized time complexity for both union and find operations becomes nearly constant. It is expressed as O(α(n)), where α(n) is the inverse Ackermann function.

The inverse Ackermann function, α(n), grows extremely slowly. For any practical value of n (even numbers far larger than the estimated number of atoms in the universe), α(n) is less than 5. Therefore, for all practical purposes, the time complexity with these optimizations is often considered to be effectively constant time, sometimes loosely referred to as O(1) on average per operation over a sequence of operations.

**Complexity with Partial Optimizations:**

Union by Rank/Size only (without Path Compression): The find operation has a worst-case time complexity of O(logn).
Path Compression only (without Union by Rank/Size): For a sequence of m operations (unions and finds) on n elements, the total time can be O(mlogn). This makes the amortized cost of a find operation O(logn).

## MST intro

What is a Spanning Tree?
Given an undirected and connected graph **G=(V,E)**, a spanning tree of the graph **G** is a tree that spans **G** (that is, it includes every vertex of **G**) and is a subgraph of **G** (every edge in the tree belongs to **G** )

What is a Minimum Spanning Tree?
The cost of the spanning tree is the sum of the weights of all the edges in the tree. There can be many spanning trees. Minimum spanning tree is the spanning tree where the cost is minimum among all the spanning trees. There also can be many minimum spanning trees.

![Screenshot 2022-01-19 184249](https://user-images.githubusercontent.com/65967989/150175470-9aa7ff87-d644-40e4-9299-0e3ef8c4a0f8.jpg)

**There are two famous algorithms for finding the Minimum Spanning Tree:**

**Kruskal’s Algorithm**
Kruskal’s Algorithm builds the spanning tree by adding edges one by one into a growing spanning tree. Kruskal's algorithm follows greedy approach as in each iteration it finds an edge which has least weight and add it to the growing spanning tree.

**Algorithm Steps:**

- Sort the graph edges with respect to their weights.
- Start adding edges to the MST from the edge with the smallest weight until the edge of the largest weight.
- Only add edges which doesn't form a cycle , edges which connect only disconnected components.

So now the question is how to check if **2** vertices are connected or not ?

This could be done using DFS which starts from the first vertex, then check if the second vertex is visited or not. But DFS will make time complexity large as it has an order of **O(V+E)**  where **V** is the number of vertices, **E** is the number of edges. So the best solution is "Disjoint Sets":
Disjoint sets are sets whose intersection is the empty set so it means that they don't have any element in common.

**Consider following example:**


![Screenshot 2022-01-19 184715](https://user-images.githubusercontent.com/65967989/150176132-c1f2ea20-ec2b-426f-bb22-c1ae28c082e2.jpg)



In Kruskal’s algorithm, at each iteration we will select the edge with the lowest weight. So, we will start with the lowest weighted edge first i.e., the edges with weight 1. After that we will select the second lowest weighted edge i.e., edge with weight 2. Notice these two edges are totally disjoint. Now, the next edge will be the third lowest weighted edge i.e., edge with weight 3, which connects the two disjoint pieces of the graph. Now, we are not allowed to pick the edge with weight 4, that will create a cycle and we can’t have any cycles. So we will select the fifth lowest weighted edge i.e., edge with weight 5. Now the other two edges will create cycles so we will ignore them. In the end, we end up with a minimum spanning tree with total cost 11 ( = 1 + 2 + 3 + 5).

**Time Complexity:**
In Kruskal’s algorithm, most time consuming operation is sorting because the total complexity of the Disjoint-Set operations will be **O(E logV)** , which is the overall Time Complexity of the algorithm.

The second algorithm os `Prim's` algorithm .


## Good problems
- https://codeforces.com/contest/1131/problem/F
- https://codeforces.com/problemset/problem/1176/E
- https://www.spoj.com/problems/KOICOST/en/ .._solution_..https://drive.google.com/file/d/1iQz0gr1cNRQijJFp2zk0A5eMZijL1ca6/view


