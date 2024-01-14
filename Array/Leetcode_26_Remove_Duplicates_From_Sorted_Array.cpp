/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears 
only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums 
initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

### Constraints:
    1 <= nums.length <= 3 * 104
    -100 <= nums[i] <= 100
    nums is sorted in non-decreasing order.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int N = nums.size();
        if ( N == 1)
            return N;
        for ( int i = 0; i < N - 1; i++ )
        {
            if (nums[i]  != nums[i +1])
            {
                nums[k++] = nums[i];
            }
        }
        nums[k++] = nums[N-1];  
        return k;
    }
};