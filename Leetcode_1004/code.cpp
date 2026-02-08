#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Counting no. of zeros in the  sliding window
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int max_count = 0;
        int zero_count = 0;
        int left = 0;

        for ( int right = 0; right < n; right++)
        {
            if(nums[right] == 0)
                zero_count++;

            while (zero_count> k)
            {
                if (nums[left] == 0)
                    zero_count--;
                left++;
            }
            max_count = max(max_count, right-left+1);
        }
        return max_count;
    }
    // Counting no. of ones in the  sliding window
    int longestOnes_2(vector<int>& nums, int k) {

        int n = nums.size();
        int max_count = 0;
        int ones_count = 0;
        int left = 0;

        for ( int right = 0; right < n; right++)
        {
            if(nums[right])
                ones_count++;

            while (right - left + 1 - ones_count > k)
            {
                if (nums[left])
                    ones_count--;
                left++;
            }
            max_count = max(max_count, right-left+1);
        }
        return max_count;
    }
};

int main()
{
    vector<int> v = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    Solution sol;

    cout << sol.longestOnes(v, k) << endl;   //expects 6
    cout << sol.longestOnes_2(v, k) << endl;   //expects 6

    vector<int> v1 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int  k1 = 3;
    cout << sol.longestOnes(v1, k1) << endl;   //expects 10
    cout << sol.longestOnes_2(v1, k1) << endl;   //expects 10

    return 0;
}
