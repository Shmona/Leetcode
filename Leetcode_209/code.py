from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        res = float('inf')
        temp = 0
        left = 0

        for right , x in enumerate(nums):
            temp += x
            while (left <= right and temp >= target):
                res = min(res, right-left + 1)
                temp -= nums[left]
                left += 1
        return 0 if res ==  float('inf') else res      
    

if __name__ == "__main__":
    sol = Solution()
    v = [2,3,1,2,4,3]
    target = 7
    print(f" Minimal length of a subarray whose sum is greater than or equal to {target} is {sol.minSubArrayLen(target, v)}")
    v1= []
    print(f" Minimal length of a subarray whose sum is greater than or equal to {target} is {sol.minSubArrayLen(target, v1)}")
