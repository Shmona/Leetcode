# Problem Statement : Single Number III

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

**Example 1:**

    Input: nums = [1,2,1,3,2,5]
    Output: [3,5]
    Explanation:  [5, 3] is also a valid answer.

**Example 2:**

    Input: nums = [-1,0]
    Output: [-1,0]

**Example 3:**

    Input: nums = [0,1]
    Output: [1,0]
 
## Constraints:

- 2 <= nums.length <= 3 * 10^4
- -2^31 <= nums[i] <= 2^31 - 1
- Each integer in nums will appear twice, only two integers will appear once.

## Approach :
**IDEA**
- XOR all numbers:

        Duplicates cancel out (x ^ x = 0)
        Result becomes: xorsum = a⊕b  ,  where a and b are the two unique numbers.

- Find a bit where a and b differ:

    - Take the rightmost set bit of xorsum
    - mask = xorsum & (~ (xorsum - 1))   or   mask = xorsum & (-xorsum)
    - This bit is 1 in exactly one of (a, b), meaning it can separate numbers into two groups.

- Partition numbers into two groups using this bit:

    Group 1: numbers with (num & mask) != 0
    Group 2: numbers with (num & mask) == 0

- XOR within each group:

    All duplicated values still cancel inside their group.
    You will end up with the two uniques.

### Using XOR split : TC = O(N) , SC = O(1)
- Solution Link :  https://leetcode.com/problems/single-number-iii/submissions/1947725334/

- Traverse the array and compute xorsum
- compute mask as xorsum & (-xorsum) i.e rightmost set bit of xorsum
- Traverse the array and check which number has rightmost set bit   

        (mask & nums[i] != 0)  => take it as group 1 => res[0]
        (mask & nums[i] == 0)  => take it as group 2 => res[1]
- return res

- NOTE : Take xorsum as long long to avoid any undefined behavior (UB)  
