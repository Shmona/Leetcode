# Problem Statement :  First Bad Version

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

 
**Example 1:**

    Input: n = 5, bad = 4
    Output: 4
    Explanation:
    call isBadVersion(3) -> false
    call isBadVersion(5) -> true
    call isBadVersion(4) -> true
    Then 4 is the first bad version.

**Example 2:**

    Input: n = 1, bad = 1
    Output: 1
 
## Constraints:
- 1 <= bad <= n <= 2^31 - 1

## Approach 
### Using Binary Search : TC = O(Log N) , SC = O(1)
- Solution Link :  https://leetcode.com/problems/first-bad-version/submissions/1922471106/

- Array values are in ascending order 1 .. n
- Take extremes ends low => 1 and high => n
- while low < high:
  
        => compute mid and check whether mid is BadVersion or not
        => if mid is bad version :  narrow the search window by moving high => mid 
        => else : narrow the search window by moving low  => mid + 1
  
- return high as answer
