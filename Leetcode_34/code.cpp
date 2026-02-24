#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    //Naive Solution TC = O(N) , SC = O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res {-1, -1};
        int n = nums.size();

        if (n == 0)
            return res;
        if (n == 1)
        {
            if (nums[0] == target)
                return {0,0};
        }
        int start = 0;
        while (start < n  && nums[start] != target)
            start++;
        
        // if target is found
        if (start != n)
        {
            res[0] = start;
            while (start < n && nums[start] == target)
                start++;
            res[1] = start - 1;
        }
        return res;
    }

    //Binary Search TC = O(Log N) , SC = O(1)
    vector<int> searchRange_BS(vector<int>& nums, int target) {
        int start = Firstoccur(nums, target);

        if (start == -1)
            return {-1, -1};
        int end = Lastoccur(nums,target);

        return {start, end};
    }
    private:
        int Firstoccur(vector<int>& nums, int target)
        {
            int low = 0, high = nums.size() - 1;
            int ans = -1;
            while (low <= high)
            {
                int mid = low + (high - low)/2;
                if (nums[mid] >= target)
                {
                    if (nums[mid] == target)
                        ans = mid;
                    high = mid - 1;
                }
                else 
                    low = mid + 1;
            }
            return ans;
        }
        int Lastoccur(vector<int>& nums, int target)
        {
            int low = 0, high = nums.size() - 1;
            int ans = -1;
            while (low <= high)
            {
                int mid = low + (high - low)/2;
                if (nums[mid] <= target)
                {
                    if (nums[mid] == target)
                        ans = mid;
                    low = mid + 1;
                }
                else 
                    high = mid - 1;
            }
            return ans;
        }
};

int main()
{
    Solution sol;
    vector<int> v1 = {5,7,7,8,8,10};

    int t1 = 8;
    vector<int> res1 = sol.searchRange(v1, t1);
    cout << "\n Range of " << t1 << " is :";
    for( auto x : res1)
        cout << x << "  ";

    vector<int> res11 = sol.searchRange_BS(v1, t1);
    cout << "\n Range of " << t1 << " is :";
    for( auto x : res11)
        cout << x << "  ";

    int t2 = 6;
    vector<int> res2 = sol.searchRange(v1, t2);
    cout << "\n Range of " << t2 << " is :";
    for (auto x : res2)
        cout << x << "  ";

    vector<int> res22 = sol.searchRange_BS(v1, t2);
    cout << "\n Range of " << t2 << " is :";
    for (auto x : res22)
        cout << x << "  ";

    return 0;
}
