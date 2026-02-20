#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int res = 0;
        int left = 0, right = n -1;
        int leftmax = INT_MIN, rightmax = INT_MIN;
        
        while(left < right)   
        {
            if (height[left] < height[right])
            {
                leftmax = max(leftmax, height[left]);
                res += leftmax - height[left];
                left++;
            }
            else
            {
                rightmax = max(rightmax, height[right]);
                res += rightmax - height[right];
                right--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {0,1,0,2,1,0,1,3,2,1,2,1}; 
    cout << sol.trap(v1) << endl;                // expects 6

    vector<int> v2 = {4,2,0,3,2,5};
    cout << sol.trap(v2) << endl;    //expects 9

    return 0;
}
