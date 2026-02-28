#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
    public:
        int smallestDivisor(vector<int>& nums, int threshold) {
            int low = 1;
            int high = *max_element(nums.begin(), nums.end());

            int ans = high;
            while(low <= high)
            {
                int mid = low + (high - low)/2;
                if (sum_formed(nums, mid, threshold))
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
        bool sum_formed(vector<int>& nums, int divisor, int threshold)
        {
            int sum = 0;
            for (auto x : nums)
            {
                sum += (x + divisor - 1)/divisor;
                if (sum > threshold)
                    return false;
            }
            return true;
        }

};

int main()
{
    Solution sol;
    vector<int> v1 = {1,2,5,9};
    int t1 = 6;
    cout << sol.smallestDivisor(v1, t1) << endl;  //expects 5

    vector<int> v2 = {44,22,33,11,1};
    int t2 = 5;
    cout << sol.smallestDivisor(v2, t2) << endl;  //expects 44

    vector<int> v3 = {21212,10101,12121};
    int t3 = 1000000;
    cout << sol.smallestDivisor(v3, t3) << endl;  //expects 1

    return 0;
}
