#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        vector<int> res(2,0);

        long long xorsum = 0;
        for (auto x : nums)
            xorsum ^= x;
            
        int mask =  xorsum & (-xorsum );

        for (auto x : nums)
        {
            if (mask & x)
                res[0] ^= x;
            else
                res[1] ^= x;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1,2,1,3,2,5};

    vector<int> res = sol.singleNumber(v1);   // expects { 3, 5}
    cout << " \n Result : ";
    for (auto x : res)
        cout << x << " ";
    
    vector<int> v2 = {-1,0};
    vector<int> res1 = sol.singleNumber(v2);  // expects { -1, 0}
    cout << " \n Result : ";
    for (auto x : res1)
        cout << x << " ";

    vector<int> v3 = {1,1,0, -2147483648};
    vector<int> res2 = sol.singleNumber(v3);  // expects { 0, -2147483648}
    cout << " \n Result : ";
    for (auto x : res2)
        cout << x << " ";

    return 0;
}
