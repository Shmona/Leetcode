from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:

        left = 0
        right = len(height) - 1
        res = 0

        while (right > left):
            temp = min(height[right], height[left]) * (right - left)
            res = max(res, temp)

            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
        return res

if __name__ == "__main__":
    sol = Solution()
    tests = [
        ([1,8,6,2,5,4,8,3,7], 49),
        ([1,1], 1),
        ([4,3,2,1,4], 16),
        ([1,2,1], 2),
        ([], 0),
        ([5], 0),
    ]
    for arr, expected in tests:
        a1 = sol.maxArea(arr)
        print(arr, "→", a1, "expected:", expected)
        assert a1 == expected 
    
