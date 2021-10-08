# Content
- [Introduction](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/README.md#introduction)
- [Rabin-Karp](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/RabinKarp.cpp)

## Introduction
Many string problems can be solved easily in `O(n^2)` but that brute force solution can be replaced by more efficient algorithms that work in `O(n)` or `O(n log n)` time . For example **the pattern-matching** problem can be easily solved in `O(n*m)` n : the string length , m : the pattern length , but we can reduce that time to `O(n+m)` using Rabin-Karp algorithm .

## Rabin-Karp
**The probability** of mistake = the probability of collisions = `1/P` which is quite sufficient but to make it more precise we use two hash function each with a different P .

**There's two implementations** to this algorithm one using pushBack/popFront function while the second uses pushFront/popBack functions .

### Resources
- https://www.youtube.com/watch?v=BfUejqd07yo
