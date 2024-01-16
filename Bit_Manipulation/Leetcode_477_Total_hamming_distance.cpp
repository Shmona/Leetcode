/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

 
Example 1:
    Input: nums = [4,14,2]
    Output: 6
    Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
    showing the four bits relevant in this case).
    The answer will be:
    HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

Example 2:
    Input: nums = [4,14,4]
    Output: 4

###Constraints:
    1 <= nums.length <= 104
    0 <= nums[i] <= 109
    The answer for the given input will fit in a 32-bit integer.
*/
/* NAIVE APPROACH
Time complexity = O(N*N)
Space complexity = O(1)

Does not pass Leetcode criteria

*/
class Solution {
public:
    int hamming(int a, int b)
    {
        int res = a ^ b;
        int count=0;
        while (res)
        {
            res = res & ( res - 1 );
            count++;
        }
        return count;
    }
    int totalHammingDistance(vector<int>& nums) {

        int ans = 0;
        for ( int i = 0; i < nums.size(); i++)
        {
            for ( int j = i + 1; j < nums.size(); j++)
            {
                ans = ans + hamming ( nums[i], nums[j]);
            }
        }
        return ans;
    }
};
/* BETTER APPROACH
Time complexity = O(N*32)
Space complexity = O(1)
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            // to count the numbers having LSB = 1
            int count = 0;
            for ( int j = 0; j < N; j++)
            {
                //check i th bit of each number
                if ((nums[j] >> i)& 1)
                    count++;
            }
            ans += count*(N - count);
        }
        return ans;
    }
};


/* Other  APPROACH
Time complexity = O(N*30)
Space complexity = O(1)
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int N = nums.size();
        int BITS = 30; // bits needed to represent the max nums[i]
        int ans = 0;
        for (int i = 0; i < BITS; i++)
        {
            // to count the numbers having LSB = 1
            int count = 0;
            for ( int j = 0; j < N; j++)
            {
                //check i th bit of each number
                if ((nums[j] >> i)& 1)
                    count++;
            }
            ans += count*(N - count);
        }
        return ans;
    }
};

/*
BEST APPROACH
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int count[30][2] = {0};
        
        for ( int x : nums)
        {
            for (int i = 0; i < 30; i++)
            {
                ++count[i][x&1];
                x >>= 1;
            }
        }
        for (int i = 0; i < 30; i++)
            ans += count[i][0] * count[i][1];
        return ans;
    }
};
