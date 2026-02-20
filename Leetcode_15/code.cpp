#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3)
            return res;
            
        sort(nums.begin(), nums.end());
        
        for ( int k = 0; k < n - 2; k++)
        {
            if (k > 0 && nums[k] == nums[k - 1]) 
                continue;

            int left = k+1, right = n-1;
            while (left < right)
            {
                int sum =  nums[k] + nums[left] + nums[right];
                if (sum == 0)
                {
                    res.push_back({nums[k], nums[left], nums[right] });
                    while(left < right && nums[left] == nums[left+1])
                        left++;

                    while(left < right && nums[right] == nums[right-1])  
                        right--;
                    
                    left++;
                    right--;
                }
                else if (sum < 0)
                    left++;
                else 
                    right--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {-1,0,1,2,-1,-4};
    vector<vector<int>> res1 = sol.threeSum(v1);    //expects [[-1,-1,2],[-1,0,1]]

    cout << "\n Possible triplets are : \n";
    for (auto x : res1)
    { 
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}
