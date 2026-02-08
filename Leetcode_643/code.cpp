#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        if (k == 0 || n == 0)
            return 0.0;
        long long sum = 0;
        long long ans = LLONG_MIN;

        for ( int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (i >= k - 1)
            {
                ans = max(sum, ans);
                sum -= nums[i-k+1];
            }
        }
        return double(ans)/k;
    }
};


int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    Solution sol;
    cout << sol.findMaxAverage(nums, k) << endl;    // expected: 12.75
    
    vector<int> nums1 = {-5};
    cout << sol.findMaxAverage(nums1, 1) << endl; 
    return 0;
}
