/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of 
a given target value.

If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

Example 2:
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]

Example 3:
    Input: nums = [], target = 0
    Output: [-1,-1]
 
###Constraints:
    0 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
    nums is a non-decreasing array.
    -10^9 <= target <= 10^9
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res (2, -1);

        if (nums.size() < 1)
            return res;
        
        if (nums.size() == 1 && nums[0] == target)
            return {0,0};
            
        int i = 0;
        bool flag = false;
        while(i < nums.size())
        {
            if (nums[i] == target)
            {
                flag = true;
                break;
            }
            i++;
        }
        if (flag == false)
            return res;
        else if ( i < nums.size())
        {
            res[0] = i;
            while (i < nums.size() && nums[i] == target)
                i++;
            res[1] = i - 1;
        }
        return res;   
    }
};

//More compact
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res (2, -1);

        if (nums.size() < 1)
            return res;

        for ( int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                res[0] = i;
                i++;
                while (i < nums.size() && nums[i] == target)
                    i++;
            
                res[1] = i - 1;
                
                return res;
            }
        }
        return res;   
    }
};