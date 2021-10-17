# Content
- [Introduction](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/README.md#introduction)
- [Rabin-Karp](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/RabinKarp.cpp)
- [KMP](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/KMP.cpp)
- [Trie Data-Structure](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/trie.cpp)
- [Find String](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/findString.cpp)
- [Pattern-Query](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/PatternQuery.cpp)

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

## Trie Data-Structure intro from HackerEarth
Tries are an extremely special and useful data-structure that are based on the prefix of a string. They are used to represent the “Retrieval” of data and thus the name Trie.
A Trie is a special data structure used to store strings that can be visualized like a graph. It consists of nodes and edges. Each node consists of at max 26 children and edges connect each parent node to its children. These 26 pointers are nothing but pointers for each of the 26 letters of the English alphabet A separate edge is maintained for every edge.

Strings are stored in a top to bottom manner on the basis of their prefix in a trie. All prefixes of length 1 are stored at until level 1, all prefixes of length 2 are sorted at until level 2 and so on.
For example , consider the following diagram :
![fb14630](https://user-images.githubusercontent.com/65967989/137604847-6c26db13-589d-42fd-9288-d8c3c92071b1.png)

Now, one would be wondering why to use a data structure such as a trie for processing a single string? Actually, Tries are generally used on groups of strings, rather than a single string. When given multiple strings , we can solve a variety of problems based on them. For example, consider an English dictionary and a single string , find the prefix of maximum length from the dictionary strings matching the string . Solving this problem using a naive approach would require us to match the prefix of the given string with the prefix of every other word in the dictionary and note the maximum. The is an expensive process considering the amount of time it would take. Tries can solve this problem in much more efficient way. **Actually after building the trie , the time it'll take to determine the length of the logest common prefix "L" is O(|L|)**

## Find String
In this problem , we have n number of strings and q number of queries each consists of a string that've te be determined if present in our previously entered collection. The idea is to make a trie out of the collection and then for each query we traverse the trie to see if we can get the string-of-the-query .

there's a limitation to this implementation : if one of the strings in the collection is a prefix of another string , then if we searched for the shortter one , it'll return that's not present ... to solve this :
 - 1 : in the add function we make sure that the last node of the string (no matter it's already present or just got created) is a leaf .
 - 2 : sort the strings in a descending order regarding their length before adding to the trie .
 see [limitationSolved](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/String%20Algorithms/limitationSolved.cpp)
 
## Pattern Query
In this problem we have a string and q queries .. each one represents a pattern .. The question is how many patterns are represented in the string as subs. The main idea is to make a trie out of all the patterns and then starting from each char of the string we travers the trie trying to find a leaf . The previously discussed limitation of the trie will affect the answers so pay attention .
 
