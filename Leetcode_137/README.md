# Problem Statement :  Single Number II
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.


**Example 1:**

    Input: nums = [2,2,3,2]
    Output: 3

**Example 2:**

    Input: nums = [0,1,0,1,0,1,99]
    Output: 99
 
## Constraints:
- 1 <= nums.length <= 3 * 10^4
- -2^31 <= nums[i] <= 2^31 - 1
- Each element in nums appears exactly three times except for one element which appears once.

## Approach :
### using frequency map : TC = O(N) , SC = O(K + 1) , K is no. of distinct numbers
- Solution Link : https://leetcode.com/problems/single-number-ii/submissions/1942750168/

- create a frequency map to store the count of each distinct number present in the given array
- Traverse the frequency map and check the count of each entry
- if count < 3 =>  return that entry as answer


### using bit counting modulo 3 (appears 3 times except one): TC = O(N) , SC = O(1) 
- Solution Link : https://leetcode.com/problems/single-number-ii/submissions/1943731749/

- Maintain bitwise state variables to track how many times each bit has appeared modulo 3.

        - ones =  Tracks bits that have appeared once (mod 3)
        - twos =  Tracks bits that have appeared twice (mod 3)
        - threes =  Temporary mask (Used only for clearing) for bits that have appeared three times (mod 3)

- For each number x:
    - Add bits into twos if they’re already in ones
    - Toggle bits in ones
    - Clear bits that are now in both (threes)

- return ones as answer

### using Generic bit counting : bit counting modulo k (appears k times except one) : TC = O(N * 32) , SC = O(1) 
**IDEA**
- Each integer can be viewed as 32 independent bit positions (for 32-bit ints).
- For any bit position b:

        - If a number appears k times, its bit contributes k occurrences at that bit.
        - Taking the total count modulo k removes all contributions from repeated numbers.
        - Only the unique number (appearing once) leaves a remainder of 1 for the bits it has set.

    - So for each bit position:
            count_ones_at_bit_b % k != 0 ⇒ bit b belongs to the unique number.


- Solution Link : https://leetcode.com/problems/single-number-ii/submissions/1943733666/

- Initialize ans = 0
- For each bit position b from 0 to 31:

        Count how many numbers in nums have bit b set.
        Compute count % k.
        If the remainder is non-zero, set bit b in ans.

-  Return ans.
