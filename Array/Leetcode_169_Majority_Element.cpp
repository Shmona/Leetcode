/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than |n/2| times. 
You may assume that the majority element always exists in the array.

Example 1:
    Input: nums = [3,2,3]
    Output: 3

Example 2:
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2

### Constraints:
        n == nums.length
        1 <= n <= 5 * 104
        -109 <= nums[i] <= 109

Could you solve the problem in linear time and in O(1) space?
*/

/* BEST APPROACH
Time complexity = O(N*BITS)
Space Complexity = O(1)*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int N = nums.size();

        if (N == 1)
            return nums[0];
        
        int ans = 0;
        int BITS = sizeof(int)*8;
        
        for (int i = 0 ; i < BITS; i++ )
        {
            int count = 0;
            for ( int j = 0; j < N; j++)
            {
                if(nums[j] & (1 << i))
                    count++;
            }
            
            if (count > N/2)
                ans += (1<<i) ;
        }
        return ans;   
    }
};

/*Using Map 
Time Complexity = O(N)
Space Complexity = O(N)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int N = nums.size();

        if (N == 1)
            return nums[0];
        
        int ans = -1;
        map <int, int> res;
        for (int i = 0 ; i < N; i++ )
        {
            res[nums[i]]++;
            if (res[nums[i]] > N/2)
                ans = nums[i] ;
        }
        return ans;   
    }
};

//Another Approach : using Sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};