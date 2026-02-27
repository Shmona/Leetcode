#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low)/2;
            if (split_needed(nums, mid) <= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

private:
    int split_needed(vector<int> &nums, int minSum)
    {
        long long curr = 0;
        int ans = 1;
        for (auto x : nums)
        {
            if (curr + x <= minSum)
                curr += x;
            else
            {
                ans++;
                curr = x;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {7,2,5,10,8};
    int k1 = 2;

    cout << sol.splitArray(v1, k1) << endl;   //expects 18

    vector<int> v2 = {1,2,3,4,5};
    cout << sol.splitArray(v2, k1) << endl;   //expects 9

    return 0;
}
