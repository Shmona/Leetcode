# Problem Statement 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

**Example 1:**

    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

**Example 2:**

    Input: height = [4,2,0,3,2,5]
    Output: 9
 
## Constraints:
- n == height.length
- 1 <= n <= 2 * 10^4
- 0 <= height[i] <= 10^5
 
## Approach
**Using Two Pointer : TC = O(N), SC = O(1)**
- Traverse the array maintaining two pointers pointing at extremes left => 0 and right => n-1
- Keep track of leftmax and rightmax 
- while left < right , keep comparing height[left] with height[right]
    
        if height[left] < height[right], 
            update leftmax = max (leftmax, height[left])
            ans += leftmax - height[left]
            move left pointer 

        if height[left] > height[right], 
            update rightmax = max (rightmax, height[right])
            ans += rightmax - height[right]
            move right pointer 
- return ans
