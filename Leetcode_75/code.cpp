#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = n-1, mid = 0;

        while ( mid  <= right)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[left]);
                left++;
                mid++;
            }
            else if (nums[mid] == 1)
                mid++;
            else
            {
                swap(nums[mid], nums[right]);
                right--;
            }          
        }
    }

    void sortColors_sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {2,0,2,1,1,0};
    sol.sortColors(v1);
    cout << "\n Sorted Colored using 3 Pointers : red = 0, white = 1, Blue = 2 :\n";
    for (auto x : v1)
        cout << x << "  ";

    vector<int> v2 = {2,0,1};
    sol.sortColors(v2);
    cout << "\n Sorted Colored using 3 Pointers : red = 0, white = 1, Blue = 2 :\n";
    for (auto x : v2)
        cout << x << "  ";

    vector<int> v3 = {2,0,2,1,1,0};
    sol.sortColors(v3);
    cout << "\n Sorted Colored using sorting: red = 0, white = 1, Blue = 2 :\n";
    for (auto x : v3)
        cout << x << "  ";

    vector<int> v4 = {2,0,1};
    sol.sortColors(v4);
    cout << "\n Sorted Colored  using sorting: red = 0, white = 1, Blue = 2 :\n";
    for (auto x : v4)
        cout << x << "  ";


    return 0;
}
