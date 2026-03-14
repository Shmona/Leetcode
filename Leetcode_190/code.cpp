#include <iostream>

using namespace std;
class Solution {
public:
    //Naive Solution 
    int reverseBits(int n) {

        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & 1)
                res |= 1 << (31 - i);
            
            n >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;

    cout << sol.reverseBits(43261596) << endl;  //expects 964176192
    return 0;
}
