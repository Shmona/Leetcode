/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
    Input: nums = [3,2,3]
    Output: [3]

Example 2:
    Input: nums = [1]
    Output: [1]

Example 3:
    Input: nums = [1,2]
    Output: [1,2]
 
###Constraints:
    1 <= nums.length <= 5 * 10^4
    -10^9 <= nums[i] <= 10^9
 

Follow up: Could you solve the problem in linear time and in O(1) space?
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if ( n ==1)
            return nums;
        
        vector<int> res;
        unordered_map<int,int> s;

        for (int i = 0; i < n; i++)
            s[nums[i]]++;
        
        for (auto x: s)
        {
           int key = x.first;
           int count = x.second;

           if (count > n/3)
                res.push_back(key);
        }
        return res; 
    }
};