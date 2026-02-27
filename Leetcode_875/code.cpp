#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int low = 1;
            int high = *max_element(piles.begin(), piles.end());
            int ans = high;

            while (low <= high)
            {
                int mid = low + (high - low)/2;
                if (hours_needed(piles,h, mid) <= h)
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
        long long  hours_needed(vector<int> & piles, int h, int k)
        {
            long long ans = 0;
            for (auto p : piles)
            {
                ans += (p + k - 1)/k;
                if (ans >  h)
                    break;
            }
            return ans;
        }

};

int main()
{
    Solution sol;
    vector<int> v1 = {3,6,7,11};
    int h1 = 8;

    cout << sol.minEatingSpeed(v1, h1) << endl;    //expects 4

    vector<int> v2 ={30,11,23,4,20};
    int h2 = 6;

    cout << sol.minEatingSpeed(v2, h2) << endl;     //expects 23
    
    return 0;
}
