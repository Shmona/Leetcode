/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], 
nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target
    You may return the answer in any order.

Example 1:
    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
    Input: nums = [2,2,2,2,2], target = 8
    Output: [[2,2,2,2]]
 
###Constraints:
    1 <= nums.length <= 200
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        int n = nums.size();
        if (n < 4)
            return res;
        
        set<vector<int>> s;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-3; i++)
        {
            for (int j = i+1; j < n-2; j++)
            {
                int start = j+1, end = n-1;
                long long int temp = (long long int )(target) - nums[i] - nums[j];
                while(start < end)
                {
                    if (temp == (nums[start] + nums[end]))
                    {
                        s.insert({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                    }
                    else if ( temp < (nums[start] + nums[end]))
                        end--;
                    else 
                        start++;
                }
            }
        }
        for (auto it : s)
            res.push_back(it);
        return res;   
    }
};