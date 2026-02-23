#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();

            if ( n == 1 )
                return (nums[0] == target) ? 0 : -1;
            
            int start = 0;
            while(start < n-1 && nums[start] < nums[start + 1])
                start++;
            
            if (target >= nums[0] && target <= nums[start])
                return binary_search(nums, 0 , start , target);
            else
                return binary_search(nums, start + 1,  n - 1, target);
            
        }
    private:
        int binary_search(vector<int>nums, int low, int high, int target)
        {
            while (low <= high)
            {
                int mid = low + ( high - low )/2;
                if (nums[mid] == target )
                    return mid;
                else if (nums[mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return -1;
        }
};

int main()
{
    Solution sol;
    vector<int> v1 = {4,5,6,7,0,1,2};
    int t1 = 0;
    cout << sol.search(v1,t1) << endl;     // expects 4
    int t2 = 3;
    cout << sol.search(v1,t2)  << endl;    // expects -1

    vector<int> v2 = {1,3};
    cout << sol.search(v2,t1)  << endl;    // expects -1

    vector<int> v3 = {3,1};
    int t3 = 1;
    cout << sol.search(v3,t3)  << endl;    // expects 1
    return 0; 
}
