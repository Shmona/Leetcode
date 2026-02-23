#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
        // Naive Approach TC = O(N) , SC = O(1)
        int findMin(vector<int>& nums) {
            int n = nums.size();
            if ( n == 1 )
                return nums[0];
            if (nums[0] > nums[n-1])
            {
                int k = n - 1;
                while (k > 0 && nums[k] > nums[k-1])
                    k--;
                return nums[k];
            }
            else
                return nums[0];
        } 
        // Using Binary Search TC = O(Log N) , SC = O(1)
        int findMin_BS(vector<int>& nums) {
            int n = nums.size();
            if ( n == 1 )
                return nums[0];
            
            int low = 0 , high = n -1;
            while (low < high)
            {
                int mid = low + ( high - low )/2;
                if (nums[mid] > nums[high])
                    low = mid + 1;
                else
                    high = mid;
            }
            return nums[low];
        } 
};

int main()
{
    Solution sol;
    vector<int> v1 = {3,4,5,1,2};
    cout << sol.findMin(v1) << endl;   //expects 1
    cout << sol.findMin_BS(v1) << endl;   //expects 1

    vector<int> v2 = {11,13,15,17};
    cout << sol.findMin(v2) << endl;   //expects 11
    cout << sol.findMin_BS(v2) << endl;   //expects 11

    vector<int> v3 = {4,5,6,7,0,1,2};
    cout << sol.findMin(v3) << endl;   //expects 0
    cout << sol.findMin_BS(v3) << endl;   //expects 0

    return 0;
}
