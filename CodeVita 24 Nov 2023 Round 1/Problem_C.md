## C. String From Rank :

### Problem Description :

Finding the rank of a string is the basic concept one needs to learn to understand Permutations. To understand it deeply why don't we reverse engineer it?

Rank is nothing but the position of string among all the possible permutations without repetition of alphabets of length N in lexicographical order.

The possible permutations without repetition of

length 1 is a, b, c .. z,

length 2 is ab, ac, ad .. zy,

length 3 is abc, abd, abe, ... bac, bad, bae ... zyx,

and so on.

Now, given rank of a string and its length, compute the string that can be formed with all the alphabets. Check *example* section for more understanding

### Constraints :

1 < = R < = 26!

1 < = N < = 26

### Input :

First line consists of a single integer R, which denotes the rank of the string

Second line consists of a single integer N, which denotes the length of string

### Output :

Print the string of length N and rank R in a single line

Note: Formed string may or may not be a meaningful word

### Time Limit (secs) :

1

### Examples :

**Example 1 :**

**Input :**

8

1

**Output :**

h

**Explanation :**

Rank and length of string are given as 8 and 1 respectively. As the length of string is 1, the one lettered word that can be formed from all the alphabets a to z are a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.

When these words are ordered lexicographically, the word at 8^th^ position or 8^th^ rank would be 'h'. Hence, the output is 'h'.

**Example 2 :**

**Input :**

29

2

**Output :**

be

**Explanation :**

Rank and length of string are given as 29 and 2 respectively. As the length of string is 2, the two lettered word that can be formed from all the alphabets a to z are ab, ac, ad, ae, af, ag, ah, ai, aj, ak, al, am, an, ao, ap, aq, ar, as, at, au, av, aw, ax, ay, az, ba, bc, bd, be, bf and so on till zy.

When these words are ordered lexicographically, the word at 29^th^ position or 29^th^ rank would be 'be'. Hence, the output is 'be'.

---
