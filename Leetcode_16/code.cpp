#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if ( n == 3)
            return nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int ans;

        for ( int i = 0 ; i < n-2; i++)
        {
            int left = i+1, right = n-1;
            while ( left < right)
            {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == target)
                    return sum;
                else if (abs(sum - target) < abs(diff))
                {
                    diff = sum - target;
                    ans = sum;
                }
                if (sum <  target)
                    left++;
                else if (sum > target)
                    right--;
            }
        }
        return ans; 
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {-1,2,1,-4};
    int t1 = 1;
    cout << sol.threeSumClosest(v1, t1) << endl;   // expects 2

    vector<int> v2 = {0,1,2};
    int t2 = 1;
    cout << sol.threeSumClosest(v2, t2) << endl;   // expects 3

    return 0;
}
