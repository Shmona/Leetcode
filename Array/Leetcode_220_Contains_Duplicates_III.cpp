/*
You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:
1. i != j,
2. abs(i - j) <= indexDiff.
3. abs(nums[i] - nums[j]) <= valueDiff, and
4. Return true if such pair exists or false otherwise. 

Example 1:
    Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
    Output: true
    Explanation: We can choose (i, j) = (0, 3).
    We satisfy the three conditions:
    i != j --> 0 != 3
    abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
    abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0

Example 2:
    Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
    Output: false
    Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, 
    so we return false.

###Constraints:
    2 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
    1 <= indexDiff <= nums.length
    0 <= valueDiff <= 10^9
*/

//NAIVE APPROACH  : Does pass, Throw TLE

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();

        for ( int i = 0; i < n-1; i++)
        {
            for ( int j = i + 1; j < n; j++)
            {
                if (abs(i-j) <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff)
                    return true;
            }
        }
        return false;
    }
};


// Optimal approach
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();

        vector<pair<int,int>> v;
        for ( int i = 0; i < n; i++)
            v.push_back({nums[i], i});
        
        sort(v.begin(), v.end());

        for ( int i = 0 ; i < n; i++)
        {
            for ( int j = i + 1; j < n; j++)
            {
                if (v[i].first+ valueDiff >= v[j].first)
                {
                    if (abs(v[i].second - v[j].second) <= indexDiff)
                        return true;
                }
                else
                    break;
            }
        }
        return false;
    }
};


