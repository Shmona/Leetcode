#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
        int minDays(vector<int>& bloomDay, int m, int k) {
            int n = bloomDay.size();

            if (m > n/k)
                return -1;

            int low = *min_element(bloomDay.begin(), bloomDay.end());
            int high = *max_element(bloomDay.begin(), bloomDay.end());
            int ans = -1;

            while (low <= high)
            {
                int mid = low + (high - low)/2;
                if (formed_bouquets(bloomDay, k, mid) >= m)
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
        int formed_bouquets(vector<int> &bloomDay, int k, int days)
        {
            int bouquets = 0;
            int consecutive = 0;
            for (auto b : bloomDay)
            {
                if (b <= days)
                {
                    consecutive++;
                    if (consecutive == k)
                    {
                        bouquets++;
                        consecutive = 0;
                    }
                }
                else
                    consecutive = 0;
            }
            return bouquets;
        }
};

int main()
{
    Solution sol;
    vector<int> b1 = {1,10,3,10,2};
    int m1 = 3, k1 = 1;
    cout << sol.minDays(b1,m1, k1) << endl;  //expects 3

    int k2 = 2;
    cout << sol.minDays(b1,m1, k2) << endl;  //expects -1

    vector<int> b3 = {7,7,7,7,12,7,7};
    int m3 = 2, k3 = 3;
    cout << sol.minDays(b3,m3, k3) << endl;  //expects 12

    return 0;
}
