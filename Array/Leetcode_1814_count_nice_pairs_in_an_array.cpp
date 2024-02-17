/*
You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse 
of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice 
if it satisfies all of the following conditions:
    0 <= i < j < nums.length
    nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
    Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

Example 1:
    Input: nums = [42,11,1,97]
    Output: 2
    Explanation: The two pairs are:
    - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
    - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.

Example 2:
    Input: nums = [13,10,35,24,76]
    Output: 4
 
###Constraints:
    1 <= nums.length <= 10^5
    0 <= nums[i] <= 10^9
*/
// NAIVE APPROACH : Throw TLE
class Solution {
public:
    int revnum (int n)
    {
        int res = 0;
        while (n)
        {
            res = res*10 + (n%10);
            n = n/10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n-1; i++)
        {
            for( int j = i + 1; j < n; j++)
            {
                if (nums[i] + revnum(nums[j]) == nums[j] + revnum(nums[i]))
                    count++;
            }
        }
        return count;
    }
};

//Better approach
class Solution {
public:
    int revnum (int n)
    {
        int res = 0;
        while (n)
        {
            res = res*10 + (n%10);
            n = n/10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long long MAX = 1000000007;
        int count = 0;

        unordered_map <int, long long> m;

        for (int i = 0; i < n; i++)
        {
            int temp = nums[i] - revnum(nums[i]);
            count = (count + m[temp])%MAX;
            m[temp]++;
        }
        return count;
    }
};