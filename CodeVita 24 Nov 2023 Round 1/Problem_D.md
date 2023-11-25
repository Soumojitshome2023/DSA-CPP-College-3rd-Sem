## D. Online Shopping :

### Problem Description :

An online shopping store announced an offer for the upcoming festive season. In order to avail that offer, we have to collect the tokens for n consecutive days and using those tokens, we can buy items in the sale.

Mithra, a regular customer, wanted to claim those tokens and decided to buy something in the sale. When the tokens season began, she started claiming the tokens. Unfortunately, in between the days, she forgot claiming and missed few tokens. Now the token season is ended. Suddenly, the app gave bumper offer to all users i.e., for any *k* consecutive days, every user can claim the tokens if they were unclaimed in the token season.

Given an array *tokens *of size *n* denoting the number of tokens offered for *n* consecutive days and another array *claim* denoting the tokens are claimed or not on those particular days. If claim[i] is 1 then Mithra had claimed otherwise not. Another integer *k* is given denoting the number of days the bumper offer can be used. A list of items and costs are given. The only rule is that we can buy only one item using those tokens.

Help Mithra in selecting k consecutive days and finally print the item(s) which she can buy aiming for the minimal wastage of tokens. If there are more than one item of same cost, then print them in lexicographical (ascending) order.

### Constraints :

1 <= n <= 10 ^ 4

0 <= k <= 10 ^ 4

0 <= tokens[i] <= 10 ^ 4

1 <= number of items <= 100

Claim[i] is either 0 or 1

Tokens and claim are arrays of same size

### Input :

First line contains an integer *n *denoting the size of the tokens array.

Second line contains the array *tokens* denoting the number of tokens available for *n *consecutive days.

Third line contain *claim* array denoting whether Mithra claimed tokens or not, on these *n* days.

Fourth line contain the integer *k* denoting the number of consecutive days bumper offer can be applied.

Last line contains *items *denoting the items and their costs separated by colon.

Consider below *Examples* for better understanding.

### Output :

A single line of item(s) that Mithra can buy with the tokens. If there are more than one, print them in the lexicographical (ascending) order.

### Time Limit (secs) :

1

### Examples :

**Example 1 :**

**Input :**

8

7 5 0 2 8 6 12 1

1 0 1 1 0 1 1 0

2

Bucket:8 Cot:32 Chair:27 Cooker:37 Gas:45 Fan:34 Mug:3 Ac:100

**Output :**

Fan

**Explanation :**

Of the 8 days of token season, 5 days are already claimed. So, she has to claim from days where a claim is not yet made (wherever the value is 0 in the claim array). By virtue of this she already has 7+2+6+12 = 27 tokens.

Suppose Mithra decided to use the bumper offer for the days 4,5 or 5,6 then the total number of tokens she gains will be 7+2+8+6+12=35. Among all the given items, she can buy a fan which will result in the wastage of only 1 token. Other than fan, buying any items will result in the wastage of a greater number of tokens.

**Example 2 :**

**Input :**

12

8 3 6 22 5 0 11 1 0 4 9 6

0 1 0 1 1 0 1 0 1 0 0 0

3

Bucket:8 Cot:32 Geyser:45 Chair:27 Cooker:38 Gas:45 Fan:34 Mug:3 Ac:100 Bulb:15

**Output :**

Gas Geyser

**Explanation :**

Of the 12 days of token season, 5 days are already claimed. So, she has to claim from days where a claim is not yet made (wherever the value is 0 in the claim array). By virtue of this she already has 3+22+5+11 = 41 tokens.

Suppose Mithra decided to use the bumper offer for the days 10,11,12 then the number of tokens she gains will be 3+22+5+11+4+9+6=60. Among all the given items, she can buy gas or geyser which will result in the wastage of only 15 tokens. Other than these, buying any items will result in the wastage of a greater number of tokens.

---