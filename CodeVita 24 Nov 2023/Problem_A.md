A. Sort And Reflect :
=====================

### Problem Description :

Selection sort works by dividing the array into two parts: a sorted and an unsorted part. In each iteration, the algorithm finds the minimum element in the unsorted part and swaps it with the first element of the unsorted part. This process continues, effectively growing the sorted part of the array until the entire array is sorted.

Given two arrays A and B which are of same size and consisting of integers. Given a positive integer n, perform the selection sorting operations on array A until n number of elements move to the correct positions where they belong after the array is sorted in ascending order. Sort the second array based on the swaps in the first array and then print the second array.

Note : If duplicates are present in array A, follow the same order they occurred, while sorting.

---

### Constraints :

len(A) = len(B)

0 <= A[i],B[i] <= 10^6

1 <= len(A) <= 1000

n <= len(A)

### Input :

First line consists of elements of array A, separated by space.

Second line consists of elements of array B, separated by space.

Third line contains an integer n.

### Output :

Print the modified array B in a single line. Elements of array B should be space separated.

### Time Limit (secs) :

1

---

### Examples :

---



**Example 1 :**

**Input :**

32  4  53 2   0   18

16 11  9  3  21  36

3

**Output :**

21 3 11 9 16 36

**Explanation :**

By implementing selection sorting on A till 4 numbers get to their correct positions and reflecting the swaps on B, it will become 21 3 11 9 16 36.

---

**Example 2 :**

**Input :**

91 4 37 6 19 27 0 54 11 16

43 56 35 3 56 232 5 6 54 1

6

**Output :**

5 56 3 54 1 56 43 6 35 232

**Explanation :**

By implementing selection Sorting on A till 6 numbers get to their correct positions and reflecting the swaps on B, it will become 5 56 3 54 1 56 43 6 35 232.

---
