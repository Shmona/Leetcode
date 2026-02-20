#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = low + ( high - low )/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else    
                high = mid - 1;
        }
        return low;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = { 1,3,5,6 };
    int t1 = 5;
    cout << sol.searchInsert(v1, t1) << endl; //expects 2
    int t2 = 2;
    cout << sol.searchInsert(v1, t2) << endl; //expects 1
    int t3 = 7;
    cout << sol.searchInsert(v1, t3) << endl; //expects 4

    return 0;
}
