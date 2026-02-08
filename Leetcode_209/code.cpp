#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int res = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int right = 0; right < n; right++)
        {
            sum += nums[right];
            while (left <= right && sum >= target)
            {
                res = min(res, right-left+1);
                sum -= nums[left];
                left++;
            }  
        }
        return (res == INT_MAX) ? 0 : res;
    }
};

int main()
{
    vector<int> v= {2,3,1,2,4,3};
    int target = 7;
    Solution sol;

    cout << sol.minSubArrayLen(target , v ) << endl ; // expects 2

    vector<int> v1= {};
    cout << sol.minSubArrayLen(target , v1 );  // expects 0

    return 0;
}
