#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        int maxCoins(vector<int>& nums) {
            int n = nums.size();

            vector<int> a(n+2, 1);
            for (int i = 0 ; i < n; i++)
                a[i+1] = nums[i];

            int m = a.size();
            vector<vector<int>> dp(m, vector<int>(m,0));

            for (int len = 2; len < m; len++)
            {
                for (int l = 0; l + len < m; l++)
                {
                    int r = len + l;
                    for (int k = l + 1; k < r; k++)
                        dp[l][r] = max (dp[l][r], dp[l][k] + dp[k][r] + a[l]*a[k]*a[r]);
                }
            }
            return dp[0][m-1];
        }
};

int main()
{
    Solution sol;
    vector<int> nums = {3,1,5,8};
    cout << sol.maxCoins(nums) << endl;   //expects 167

    vector<int> nums1 = {1,5};
    cout << sol.maxCoins(nums1) << endl;   //expects 10

    vector<int> nums2 = {};
    cout << sol.maxCoins(nums2) << endl;   //expects 0

    return 0;
}
