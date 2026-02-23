#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        // Naive Solution : TC O(N) , O(1)
        int findMin(vector<int>& nums) {
            int n = nums.size();
            if ( n == 1 )
                return nums[0];
            
            if (nums[0] >= nums[n-1])
            {
                int k = n-1;
                while ( k > 0 && nums[k] >= nums[k-1])
                    k--;
                return nums[k];
            }
            return nums[0];
        }
        
        // Binary Search : TC O(Log N) , O(1)
        int findMin_BS(vector<int>& nums) {
            int n = nums.size();
            if ( n == 1 )
                return nums[0];
            int low = 0 , high = n-1;

            while ( low < high )
            {
                int mid = low + ( high - low )/2;
                if (nums[mid] == nums[high])
                    high--;
                else if ( nums[mid]  > nums[high] )
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
    vector<int> v1 = {2,2,2,0,1};
    cout << sol.findMin(v1) << endl;   //expects 0
    cout << sol.findMin_BS(v1) << endl;   //expects 0

    vector<int> v2 = {1, 3, 3};
    cout << sol.findMin(v2) << endl;   //expects 0
    cout << sol.findMin_BS(v2) << endl;   //expects 0
    return 0;
}
