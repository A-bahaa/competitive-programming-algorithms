# content
 - [0/1 Knapsack](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/iterativeDP/Knapsack01.cpp) 
 - [Coin Change 1](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/iterativeDP/coinChange1.cpp)
 - [Coin Change 2](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/iterativeDP/coinChange2.cpp)
 - [Longest Common Subsequence (LCS)](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/iterativeDP/LCS.cpp)
 - [Longest Common Substring](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/iterativeDP/LCsubstring.cpp)
 - [Longest Non Decreasing Subsequence](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/iterativeDP/LNDS.cpp)
 - [Tetrahedron](https://github.com/A-bahaa/competitive-programming-algorithms/blob/main/iterativeDP/Tetrahedron.cpp)
 - -Don't Forget the other problems

## 0/1 Knapsack
![knapsakdp](https://user-images.githubusercontent.com/65967989/135391517-a4f99e85-e0a4-444d-b8fa-00f781575c74.jpg)

### Resources
- https://www.youtube.com/watch?v=8LusJS5-AGo

## Coin Change 1
![coinchange](https://user-images.githubusercontent.com/65967989/135392607-5cde7807-6284-4dd5-8aa2-5cc039bb8b44.jpg)

**Can't we solve this problem using Greedy approach?** No , because the greedy approach wouldn't always give the right answer , for examble this test case .. total change = 11 and coins = {1 , 5 , 6 , 9} the greedy approach would answer 3 as in this list of coins {9 , 1 , 1} while the correct answer is 2 as in the list {5,6} .
### Resources
- https://www.youtube.com/watch?v=Y0ZqKpToTic&t=321s
- https://www.youtube.com/watch?v=J2eoCvk59Rc

## Coin Change 2
![CoinChange1](https://user-images.githubusercontent.com/65967989/135391522-2b129c0d-4596-4f8e-b03e-7f226f363170.jpg)

### Resources
- https://www.youtube.com/watch?v=_fgjrs570YE&t=313s

## LCS
![(309) Longest Co](https://user-images.githubusercontent.com/65967989/135411207-b4ceb618-7a58-4348-9806-c169dfeb7ac0.png)

### Resources
- https://www.youtube.com/watch?v=NnD96abizww
## Longest Common Substring
![Inked(309) Longest co (1)_LI](https://user-images.githubusercontent.com/65967989/135425924-c034d2e5-65c2-4911-bb31-c16ea84491de.jpg)

**It's very simmilar** to the LCS problem instead here we only increasing the cells when only ther's a match between the ith and the jth characters , the common substrings would be found in a diagonal shape in the dp table . Note also that the answer isn't present in the `T[n][m]` cell , so you either memorize it while looping the table or search for it after filling the dp table . 

### Resources
- https://www.youtube.com/watch?v=BysNXJHzCEs

## LNDS
![LNDS](https://user-images.githubusercontent.com/65967989/135592143-3960dbc6-48e7-43cb-ab4b-04425c910477.gif)

**There're some similar** variations to this problem like the longest (increasing , decreasing or non increasing) subsequence .

### Resources
- https://www.youtube.com/watch?v=fV-TF4OvZpk

## Tetrahedron
Problem             |  Solution
:-------------------------:|:-------------------------:
![Screenshot 2021-10-02 153121](https://user-images.githubusercontent.com/65967989/135718673-50f87a9c-122a-4994-b9e8-8b90e6489090.jpg)  |  ![Webp net-gifmaker](https://user-images.githubusercontent.com/65967989/135718513-0a2dee4c-9267-4cad-b4f9-707f7ed9e97a.gif)

**Recurrence relations :** `ways(top , n)` = 3*`ways(bottom , n-1)`   ,   `ways(bottom , n)` = 2*`ways(bottom , n-1)` + `ways(top , n-1)`

**Base case :**            `ways(top , 0)` = 1   ,   `ways(bottom , 0)` = 0

### Resources
- https://www.youtube.com/watch?v=qQwQbD8ju2s

