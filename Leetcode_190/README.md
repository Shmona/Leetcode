# Problem Statement : Reverse Bits
Reverse bits of a given 32 bits signed integer.

**Example 1:**

    Input: n = 43261596
    Output: 964176192
    Explanation:
    Integer	            Binary
    43261596	00000010100101000001111010011100
    964176192	00111001011110000010100101000000

**Example 2:**

    Input: n = 2147483644
    Output: 1073741822
    Explanation:
    Integer	                Binary
    2147483644	01111111111111111111111111111100
    1073741822	00111111111111111111111111111110
 
## Constraints:
- 0 <= n <= 2^31 - 2
- n is even.
 
        Follow up: If this function is called many times, how would you optimize it?

## Approach :

### Naive Solution : TC = O(32) , SC = O(1)
- Solution Link : https://leetcode.com/problems/reverse-bits/submissions/1948281079/

- Traverse all 32 bits of the number from left to right (i = 0 to 31).
- At each step, look at LSB of the current number:

        check  bit = n & 1.
        If the LSB is 1, set the corresponding mirrored bit in the result:
        LSB of n should become the (31 − i)th bit in res.
        So:   res |= (1 << (31 - i))

- Shift the number right by 1 to process the next bit:  n >>= 1
- After 32 iterations, res contains the bit-reversed value. Return it.
