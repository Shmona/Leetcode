from typing import List , Tuple

class Solution:
    # Naive approach  : TC = O(n^2) , SC = O(1)
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)

        for i in range(n):
            for j in range(i+1, n):
                if (nums[i] + nums[j] == target):
                    return [i, j]
        
        return [-1, -1]
    
    # Hashing : TC = O(n) = SC 
    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)

        m = dict()

        for i in range(n):
            if (target - nums[i]) not in m:
                m[nums[i]] = i
            else:
                return [i, m[target - nums[i]]]
        return [-1, -1]


if __name__ == "__main__":
    sol = Solution()
    testcases: List[Tuple[List[int], int, List[List[int]]]] = [
        ([2, 7, 11, 15], 9,  [[0, 1], [1, 0]]),
        ([3, 2, 4],      6,  [[1, 2], [2, 1]]),
        ([3, 3],         6,  [[0, 1], [1, 0]]),
        ([-1, -2, -3, -4, -5], -8, [[2, 4], [4, 2], [1, 3], [3, 1]]),
        ([1, 5, 1, 5],  10, [[1, 3], [3, 1]]),
        ([1, 2, 3],    100, [[-1, -1]]),  # no solution expected
        ([],             0, [[-1, -1]]),  # no solution expected
        ([1],            1, [[-1, -1]]),  # no solution expected
        ([0, 4, 3, 0],   0, [[0, 3], [3, 0]]),
    ]

    
    for nums, target, acceptable in testcases:
        r1 = sol.twoSum(nums, target)
        r2 = sol.twoSum2(nums, target)
        print(f"nums={nums}, target={target} -> naive={r1}, hash={r2}")

    
    assert r1 in acceptable, f"Naive failed for nums={nums}, target={target}, got {r1}, acceptable {acceptable}"
    assert r2 in acceptable, f"Hash failed for nums={nums}, target={target}, got {r2}, acceptable {acceptable}"

    print("All test cases passed ")
