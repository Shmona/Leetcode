#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
        int smallestDistancePair(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int n = nums.size();

            int low = 0;
            int high = nums[n-1] - nums[0];

            int ans = high;

            while (low <= high)
            {
                int mid = low + (high - low)/2;
                if (countPairs(nums, mid) >= k)
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
        int countPairs(vector<int>&nums, int distance)
        {
            int count = 0;
            int left = 0;
            for (int right = 1; right < nums.size(); right++)
            {
                while(nums[right] - nums[left] > distance)
                    left++;
                count += (right - left);
            }
            return count;
        }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1,3,1};
    int k1 = 1;
    cout << sol.smallestDistancePair(v1,k1) << endl;   //expects  0

    vector<int> v2 = {1,1,1};
    int k2 = 2;
    cout << sol.smallestDistancePair(v2,k2) << endl;  //expects  0

    vector<int> v3 = {1,6,1};
    int k3 = 3;
    cout << sol.smallestDistancePair(v3,k3) << endl;  //expects 5

    return 0;
}
