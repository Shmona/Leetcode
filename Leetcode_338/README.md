# Problem Statement :  Counting Bits
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.


**Example 1:**

    Input: n = 2
    Output: [0,1,1]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10

**Example 2:**

    Input: n = 5
    Output: [0,1,1,2,1,2]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10
    3 --> 11
    4 --> 100
    5 --> 101
 
## Constraints:
- 0 <= n <= 10^5
 
**Follow up:**

    It is very easy to come up with a solution with a runtime of O(n log n).
    Can you do it in linear time O(n) and possibly in a single pass?
    Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

## Approach :
### Naive Solution : TC =  O(n log n) , SC = O(n)
- Solution Link : https://leetcode.com/problems/counting-bits/submissions/1944890526/

- Create a result vector of size n + 1 and initialize all values to 0. (res[i] will store the number of set bits in i.)
- For each number i from 1 to n (inclusive):
    - Compute its bit count using the bitcount function.
    - Store the result in res[i]
- Return the result vector.

**bitcount logic**
- Repeatedly clear the rightmost set bit using: n = n & (n - 1)
- Each operation removes one 1‑bit from n.
- Increment a counter each time a bit is cleared.
- Stop when n becomes 0.
- The counter value is the number of set bits. 

### Using Dynamic Programming (Lowest-set-bit) : TC = O(n) = SC
- Solution Link : https://leetcode.com/problems/counting-bits/submissions/1944901788/

For any integer i:

    - i & (i-1) removes the lowest set bit from i
    - so res[i] = res[i & (i-1)] + 1


### Using Shift Dynamic Programming : TC = O(n) = SC
- Solution Link :  https://leetcode.com/problems/counting-bits/submissions/1944901374/

For any integer i:

    - i >> 1 is i divided by 2 (drops the last bit)
    - (i & 1) tells if i is odd (last bit is 1)
    - So  res[i] = res[i >> 1] + (i & 1)
