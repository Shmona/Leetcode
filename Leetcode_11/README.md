
# Problem Statement : Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

Notice that you may not slant the container.

**Example 1:**

    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

**Example 2:**

    Input: height = [1,1]
    Output: 1
 
## Constraints:
- n == height.length
- 2 <= n <= 10^5
- 0 <= height[i] <= 10^4

## Approach : 
### using two pointer , TC = O(N), SC = O(1)
- Solution Link :  https://leetcode.com/problems/container-with-most-water/submissions/1914902527/
  
- Traverse through the array from left to right ( left => 0 , right => n-1)
- compute area = (right - left) * min(height[left], height[right])

      : move left pointer if height[left] < height[right] as  height[left]  is already accounted to compute area
      : move right pointer if height[left] > height[right] as  height[right]  is already accounted to compute area
      : move both pointers if height[left] == height[right] as  both have been already accounted to compute area
- Keep storing the maximum area as result
