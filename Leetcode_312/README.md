# Problem Statement :  Burst Balloons

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

**Example 1:**

    Input: nums = [3,1,5,8]
    Output: 167
    Explanation:
    nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
    coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

**Example 2:**

    Input: nums = [1,5]
    Output: 10
    
## Constraints:

- n == nums.length
- 1 <= n <= 300
- 0 <= nums[i] <= 100

## Approach :
### Using Divide & Conquer + DP (Memoization) :  TC = O(N^3)  , SC = O(N^2)
- Solution Link : https://leetcode.com/problems/burst-balloons/submissions/1937569994/

- **Trick** :  To handle the boundary condition, add two virtual balloons of value 1 at both ends, a = [1] + nums + [1]
- Maintain a range [l,r], we need to find maximum coins by bursting all balloons strictly between indices l and r
- Divide step (choose last balloon k):

    - Assume balloon k is burst last among (l, r) where l < k < r.
    - By the time we burst k last, everything else in (l, r) is already gone. So its neighbors are exactly l and r.
    - Coins from bursting k last =  a[l]⋅a[k]⋅a[r]

- Conquer step (two independent subproblems):

    - Before bursting k last, we must burst:
                all balloons in (l, k)
                all balloons in (k, r)

    - So the recurrence is:
              Solve(l,r) = max (Solve(l,k) + Solve(k,r) + a[l]⋅a[k]⋅a[r])



- **DP Approach**
Let:
    - dp[l][r] = max coins obtainable by bursting balloons strictly between l and r
        So (l, r) is an open interval.

    - For every possible k with l < k < r:

          dp[l][r] = max⁡ (dp[l][r],  dp[l][k] + dp[k][r] + a[l]⋅a[k]⋅a[r] )

    - Answer  =  dp[0][n+1], where n is original nums.size().
