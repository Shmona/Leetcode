/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in 
the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
    Input: nums = [1,2,3,1], k = 3
    Output: true

Example 2:
    Input: nums = [1,0,1,1], k = 1
    Output: true

Example 3:
    Input: nums = [1,2,3,1,2,3], k = 2
    Output: false
 
###Constraints:
    1 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
    0 <= k <= 10^5
*/

//NAIVE APPROACH

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        for ( int i = 0; i < nums.size() - 1; i++)
        {
            for ( int j = i+1; j < nums.size(); j++)
            {
                if (abs(i-j) <= k)
                {
                    if (nums[i] == nums[j])
                        return true;
                }
                else
                    break;
            }
        }
        return false;
    }
};

//OPTIMAL SOLUTION
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        vector<pair<int,int>> v;

        for ( int i = 0; i < nums.size(); i++)
            v.push_back({ nums[i], i});
        
        sort(v.begin(), v.end());

        for(int i = 0; i < nums.size() -1; i++)
        {
            for ( int j = i+1; j < nums.size(); j++)
            {
                if (v[i].first == v[j].first)
                {
                    if (abs(v[i].second - v[j].second) <= k)
                        return true;
                
                }
                else
                    break;
            }
        }
        return false;
    }
};