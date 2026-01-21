from typing import List

class Solution:
    def max_area(self, height : List[int]) -> int:
        left = 0
        right = len(height) - 1
        res = 0

        while right > left:
            W = right - left
            temp = W * min(height[left],height[right])
            res = max(res, temp)

            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
        return res

    def max_area_greedy(self, height : List[int]) -> int:
        left = 0 
        right = len(height) - 1
        res = 0

        while  right > left:
            W = right - left
            if (height[left] < height[right]):
                temp = height[left] * W
                left += 1
            elif (height[left] > height[right]):
                temp = height[right] * W
                right -= 1
            else:
                temp = height[right] * W
                right -= 1
                left += 1
            res = max (res, temp)
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
        a1 = sol.max_area(arr)
        a2 = sol.max_area_greedy(arr)
        print(arr, "→", a1, a2, "expected:", expected)
        assert a1 == expected and a2 == expected
    
