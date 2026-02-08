from typing import List

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        l = len(nums)
        if k <= 0 or l < k:
            return 0.0
        
        temp = sum(nums[:k])
        ans = temp/k

        for i in range(k,l):
            temp += nums[i] - nums[i-k]
            ans = max(ans, temp/k)
        
        return ans
                

if __name__ == "__main__":
    # Example input
    nums = [1, 12, -5, -6, 50, 3]
    k = 4
    sol = Solution()
    print(f"Maximum average subarray of size {k} is: {sol.findMaxAverage(nums, 4)}")

    nums1 = [-5]
    k1 = 1
    print(f"Maximum average subarray of size {k1} is: {sol.findMaxAverage(nums1, k1)}")
   
