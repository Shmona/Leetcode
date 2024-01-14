/*
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
    Input: nums = [0]
    Output: [[],[0]]
 

### Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        // To store subset as a list to avoid adding exact duplicates
        vector<string> list;

        for ( int i = 0; i <(1<< n); i++)
        {
            vector<int> temp;
            string t = "";
            for ( int j = 0; j < n; j++)
            {   
                if ((i & (1 << j)) != 0)
                {
                    temp.push_back(nums[j]);
                    t += to_string(nums[j]) + '&';
                }
            }
            if (find(list.begin(), list.end(), t) == list.end()) 
            {
                res.push_back(temp);
                list.push_back(t);
            }
        }
        return res;   
    }
};