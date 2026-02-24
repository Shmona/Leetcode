#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n-1;

        while(low <= high)
        {
            int mid = low + ( high - low )/2;
            if ( nums[mid] == target)
                return mid;
            else if ( nums[mid] > target )
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {-1,0,3,5,9,12};
    int t1 = 9;
    cout << sol.search(v1, t1) << endl;  //expects 4

    int t2 = 2;
    cout << sol.search(v1, t2) << endl;  //expects -1
    return 0;
}
