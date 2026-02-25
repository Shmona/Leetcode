#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        if (n < 2)
            return 0;
        
        int left = 0, right = n - 1;
        int res = 0;

        while (left < right)
        {
            int area = (right - left) * min(height[left],height[right]);
            if (height[left] < height[right])
                left++;
            else if (height[left] > height[right])
                right--;
            else 
            {
                left++;
                right--;
            }
            res =  max(res, area);
        }
        return res;
    }
};

int main()
{
    vector<int> v1 = {1,8,6,2,5,4,8,3,7};
    Solution sol;

    cout << sol.maxArea(v1) << endl;  //expects 49
    return 0;
}
