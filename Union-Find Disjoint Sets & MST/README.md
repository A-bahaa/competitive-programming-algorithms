# Content
- [Intro by techiedelight]()




## Intro
**Problem:** We have some number of items. We are allowed to merge any two items to consider them equal. At any point, we are allowed to ask whether two items are considered equal or not.

A disjoint–set is a data structure that keeps track of a set of elements partitioned into several disjoint (non-overlapping) subsets. In other words, a disjoint set is a group of sets where no item can be in more than one set. It is also called a union–find data structure as it supports union and find operation on subsets. Let’s begin by defining them:

Find: It determines in which subset a particular element is in and returns the representative of that particular set. An item from this set typically acts as a “representative” of the set.

Union: It merges two different subsets into a single subset, and the representative of one set becomes representative of another.


