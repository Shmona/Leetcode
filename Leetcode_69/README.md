# Problem Statement :  
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
**Example 1:**

    Input: x = 4
    Output: 2
    Explanation: The square root of 4 is 2, so we return 2.

**Example 2:**

    Input: x = 8
    Output: 2
    Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 
## Constraints:
- 0 <= x <= 2^31 - 1

## Approach:
### Using binary search:  TC = O(Log X) , SC = O(1)
- Solution Link : https://leetcode.com/problems/sqrtx/submissions/1933228928/

- Binary search in the range [1, x]:
- while low <= high : 

    - compute mid 
    - if mid == x/mid : return mid (perfect sqrt)
    - if mid > x/mid :  discard right half and search in left half , high = mid - 1
    - if mid < x/mid :  discard left half and search in right half , left = mid + 1

- return high
