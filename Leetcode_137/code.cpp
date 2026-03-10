#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //using frequency map
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0;

        for (auto x : nums)
            map[x]++;

        for (auto m : map)
        {
            if (m.second < 3)
            {
                res = m.first;
                break;
            }
        } 
        return  res;    
    }
    //using bit counting modulo 3
    int singleNumber_BM3(vector<int>& nums) {

        int ones = 0, twos = 0;
        for (auto x : nums)
        {
            twos |= (ones & x);
            ones ^= x;

            int threes = ones & twos;

            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }

    //using bit counting modulo k
    int singleNumber_BMK(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            int mask = 1 << i;
            for (auto x : nums)
            {
                if (x & mask)
                    count++;
            }
            if (count%3 != 0)
                ans |= mask;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {2,2,3,2};
    cout << sol.singleNumber(v1) << endl;  //expects 3
    cout << sol.singleNumber_BM3(v1) << endl;  
    cout << sol.singleNumber_BMK(v1) << endl; 

    vector<int> v2 = {0,1,0,1,0,1,99};
    cout << sol.singleNumber(v2) << endl;  //expects 99
    cout << sol.singleNumber_BM3(v2) << endl;
    cout << sol.singleNumber_BMK(v2) << endl;

    return 0;
}
