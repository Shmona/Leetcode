#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Naive Solution
    int numIdenticalPairs(vector<int>& nums) {

        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if(nums[i] == nums[j])
                    count++;
            }
        }
        return count;
    }

    // Using Hashmap
    int numIdenticalPairs_HM(vector<int>& nums) {

        unordered_map<int, int> freq;
        int count = 0;
        for (auto x : nums)
        {
            count += freq[x];
            freq[x]++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1,2,3,1,1,3};
    cout << sol.numIdenticalPairs(v1) << endl;  //expects 4
    cout << sol.numIdenticalPairs_HM(v1) << endl;

    vector<int> v2 = {1,1,1,1};
    cout << sol.numIdenticalPairs(v2) << endl;  //expects 6
    cout << sol.numIdenticalPairs_HM(v2) << endl;

    vector<int> v3 = {1,2,3};
    cout << sol.numIdenticalPairs(v3) << endl;  //expects 0
    cout << sol.numIdenticalPairs_HM(v3) << endl;
    return 0;
}
