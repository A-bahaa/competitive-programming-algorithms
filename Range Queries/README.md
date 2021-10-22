# Content
- [Sparse Table](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/Range%20Queries/SparseT.cpp)




## Sparse Table
Sparse table is a data structure. It often serves as a substitute for segment tree in case of **immutable data**.

Say you have an array Arr and you want to perform some queries. Each query should compute function F over subarray [L, R]: F(ArrL, ArrL + 1, …, ArrR). With sparse table, you can do each query in `O(log(N))` ( in another implementation you can answer the query in `O(1)` ) (N is the size of Arr), with initial `O(N * log(N))` preprocessing.

Sparse table can be applied if and only if:
- Arr is immutable (i.e. queries do not change it).
- Function F is associative: F(a, b, c) = F(F(a, b), c) = F(a, F(b, c)).

Problems that can be solved using Sparse table : Range sum query , Range minimum (maximum) query , Range greatest common divisor query , etc .

This what the sparse table looks like trying to solve a min-range query .
![Screenshot 2021-10-18 215653](https://user-images.githubusercontent.com/65967989/137798229-c65ae730-248d-41c7-be89-9af9e0e4f31d.jpg)

### Resources
- https://www.youtube.com/watch?v=c5O7E_PDO4U


