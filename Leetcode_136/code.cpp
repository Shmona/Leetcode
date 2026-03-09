#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int res = 0;
        for (auto x : nums)
            res ^= x;
        
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {2,2,1};
    cout << sol.singleNumber(v1) << endl;  //expects 1

    vector<int> v2 = {4,1,2,1,2};
    cout << sol.singleNumber(v2) << endl;  //expects 4

    vector<int> v3 = {1};
    cout << sol.singleNumber(v3) << endl;  //expects 1

    return 0;
}
