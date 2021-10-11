# Content
- [Introduction](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/README.md#introduction)
- [Rabin-Karp](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/RabinKarp.cpp)
- [KMP](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/KMP.cpp)

## Introduction
Many string problems can be solved easily in `O(n^2)` but that brute force solution can be replaced by more efficient algorithms that work in `O(n)` or `O(n log n)` time . For example **the pattern-matching** problem can be easily solved in `O(n*m)` n : the string length , m : the pattern length , but we can reduce that time to `O(n+m)` using Rabin-Karp algorithm or KMP .

## Rabin-Karp
**The probability** of mistake = the probability of collisions = `1/P` which is quite sufficient but to make it more precise we use two hash function each with a different P .

**There's two implementations** to this algorithm one using pushBack/popFront function while the second uses pushFront/popBack functions .

### Resources
- https://www.youtube.com/watch?v=BfUejqd07yo

## KMP
**How to choose between Rabin-Karp and KMP?** `Rabin-Karp is easier to implement if we assume that a collision will never happen, but if the problem you have is a typical string searching KMP will be more stable no matter what input you have. However, Rabin-Karp has many other applications, where KMP is not an option.` 

**In the second implementaion** of KMP we first form the prefix vector for the string that's a combinaton of `the pattern + any char doesn't exist anywhere else + the string to search in ` , that middle char that doesn't exist anywhere else will make sure that the pattern (the prefix) doesn't extend beyound it so whenever we find a suffix that have the same length as the pattern we know we found an occurrance .

**Time complexity** `O(n+m)` .. `O(m)` to build the prefix vector and `O(n)` for pattern matching .

### Resources
- https://www.youtube.com/watch?v=GTJr8OvyEVQ
- https://www.youtube.com/watch?v=KG44VoDtsAA
- https://www.youtube.com/watch?v=BXCEFAzhxGY
