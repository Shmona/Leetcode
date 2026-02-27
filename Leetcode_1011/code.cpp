#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 

using namespace std;
class Solution{
    public:
        int shipWithinDays(vector<int>&weights, int days)
        {
            int low = *max_element(weights.begin(), weights.end());
            long long high = accumulate(weights.begin(), weights.end(), 0);
            int ans = high;

            while (low <= high)
            {
                int mid = low + (high - low)/2;
                if (days_needed(weights, mid) <= days)
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
        int days_needed(vector<int> &weights, int capacity)
        {
            long long curr = 0;
            int ans = 1;
            for (auto w : weights)
            {
                if (curr + w <= capacity)
                    curr += w;
                else
                {
                    ans++;
                    curr = w;
                }
            }
            return ans;
        }
};
int main()
{
    Solution sol;
    vector<int> w1 = {1,2,3,4,5,6,7,8,9,10};
    int d1 = 5;

    cout << sol.shipWithinDays(w1,d1) << endl;   //expects 15

    vector<int> w2 = {3,2,2,4,1,4};
    int d2 = 3;

    cout << sol.shipWithinDays(w2,d2) << endl;   //expects 6

    return 0;
}
