#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
        bool search(vector<int> nums, int target)
        {
            int n = nums.size();
            if ( n == 1 )
                return (nums[0] == target) ? true : false;
            
            int k = 0;
            while(k < n-1 && nums[k] <= nums[k + 1])
                k++;
            if (target >= nums[0] && target <= nums[k])
                return binary_search(nums, 0, k, target);
            else
                return binary_search(nums, k + 1, n-1, target);
        }
    private:
        bool binary_search(vector<int> &nums, int low, int high, int target)
        {
            while (low <= high)
            {
                int mid = low + (high - low)/2;
                if (target == nums[mid])
                    return true;
                else if ( target > nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return false;
        }
};

int main()
{
    Solution sol;
    vector<int> v1 = {2,5,6,0,0,1,2};
    int t1 = 0;
    cout << sol.search(v1, t1) << endl;   //expects true

    int t2 = 3;
    cout << sol.search(v1, t2) << endl;   //expects false

    return 0;
}
