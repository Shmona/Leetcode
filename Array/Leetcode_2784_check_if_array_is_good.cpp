/*
You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].

base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 
which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

Return true if the given array is good, otherwise return false.

Note: A permutation of integers represents an arrangement of these numbers.

Example 1:
    Input: nums = [2, 1, 3]
    Output: false
    Explanation: Since the maximum element of the array is 3, the only candidate n for 
    which this array could be a permutation of base[n], is n = 3. However, base[3] has four elements 
    but array nums has three. Therefore, it can not be a permutation of base[3] = [1, 2, 3, 3]. So the answer is false.

Example 2:
    Input: nums = [1, 3, 3, 2]
    Output: true
    Explanation: Since the maximum element of the array is 3, the only candidate n for which 
    this array could be a permutation of base[n], is n = 3. It can be seen that nums is a permutation of 
    base[3] = [1, 2, 3, 3] (by swapping the second and fourth elements in nums, we reach base[3]). 
    Therefore, the answer is true.

###Constraints:
    1 <= nums.length <= 100
    1 <= num[i] <= 200
*/

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int N = nums.size();
    
        sort(nums.begin(), nums.end());

        // First element check
        if(nums[0] != 1)
            return false;

        // Check elements from 1 to N-2 : should be 2 to N-1
        for ( int i = 1; i < N - 1; i++)
        {
            if (nums[i] != (i+1))
                return false;
        }

        //check last element
        if(nums[N-1] != N-1)
            return false;

        return true;    
    }
};