/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of 
the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

Example 2:
    Input: nums = [2,0,1]
    Output: [0,1,2]
 
###Constraints:
    n == nums.length
    1 <= n <= 300
    nums[i] is either 0, 1, or 2.
    
Follow up: Could you come up with a one-pass algorithm using only constant extra space?*/

// Using selection Sorting
class Solution {
public:
    void sortColors(vector<int>& nums) {

        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] < nums[i])
                    swap(nums[i], nums[j]);
            }
        }
    }
};

//Using COUNT Method
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int zeros_count = 0;
        int ones_count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                zeros_count++;
            else if(nums[i] == 1)
                ones_count++;
        }
        int i = 0;
        while(i < zeros_count)
        { 
            nums[i] = 0;
            i++;
        }
        
        while (i <zeros_count+ ones_count)
        {
            nums[i] = 1;
            i++;
        }
        
        while (i < nums.size())
        {
            nums[i] = 2;
            i++;
        }

    }
};