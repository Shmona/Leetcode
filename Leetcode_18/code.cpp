#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4)
            return res;
        
        sort(nums.begin(), nums.end());
        for (int a = 0 ; a < n - 3; a++)
        {
            if (a > 0 && nums[a] == nums[a - 1]) 
                continue;
            for ( int b = a + 1; b < n - 2; b++)
            {
                if (b >  a + 1 && nums[b] == nums[b - 1]) 
                    continue;

                long long sumab = (long long) target - nums[a] - nums[b];
                int left = b+1, right = n-1;
                while (left < right)
                {
                    long long sum = nums[left] + nums[right];
                    if (sum == sumab)
                    {
                        res.push_back({nums[a], nums[b], nums[left], nums[right]});
                        int lval = nums[left], rval = nums[right];
                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left-1]) 
                            left++;
                        while (left < right && nums[right] == nums[right+1]) 
                            right--;

                    }
                    else if (sum < sumab)
                        left++;
                    else    
                        right--;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1,0,-1,0,-2,2};
    int t1 = 0;

    vector<vector<int>> res1 = sol.fourSum(v1, t1);   // expects [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    cout << "\n Possible Quadruplets having sum = " << t1 << endl;
    for (auto x : res1)
    {
        for (int y : x)
            cout << y << "  ";
        cout << endl;
    }

    vector<int> v2 = {1000000000,1000000000,1000000000,1000000000};
    int t2 = -294967296;
    cout << "\n Possible Quadruplets having sum = " << t2 << endl;
    vector<vector<int>> res2 = sol.fourSum(v2, t2);   // expects []
    for (auto x : res2)
    {
        for (int y : x)
            cout << y << "  ";
        cout << endl;
    }

    
    vector<int> v3 = {-1,0,-5,-2,-2,-4,0,1,-2};
    int t3 = -9;
    vector<vector<int>> res3 = sol.fourSum(v3, t3);   // expects  [[-5,-4,-1,1],[-5,-4,0,0],[-5,-2,-2,0],[-4,-2,-2,-1]]
    cout << "\n Possible Quadruplets having sum = " << t3 << endl;
    for (auto x : res3)
    {
        for (int y : x)
            cout << y << "  ";
        cout << endl;
    }

    return 0;
}
