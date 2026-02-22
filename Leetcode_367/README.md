# Problem Statement 
Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
You must not use any built-in library function, such as sqrt.

**Example 1:**

    Input: num = 16
    Output: true
    Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

**Example 2:**

    Input: num = 14
    Output: false
    Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
 
## Constraints:
- 1 <= num <= 2^31 - 1

## Approach 
**Using binary Search TC = O(LogN), SC = O(1)**
- IDEA:
    - Any perfect square x = k × k has an integer square root k.
    - Instead of checking all possible values, search for k in the range [2, num] using binary search.

- If num == 1, return true
- Take two pointers low = 2, high = num
- while low <= right :
            
            => compute mid and compare mid * mid with num
            => To avoid integer overflow from mid × mid, we compare using division:
                    If mid == num/mid and num%mid == 0    :  perfect square, return true
                    If mid < num/mid  i.e mid*mid < num   :  search the right half, low = mid + 1
                    If mid > num/mid i.e mid*mid > num    :  search the left half, high = mid - 1
