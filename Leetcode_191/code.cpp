#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n)
        {
            n = n & (n-1);
            count++;
        }
        return count;
    }
};

int main()
{
    Solution sol;

    cout << sol.hammingWeight(128) << endl;  //expects 1 
    cout << sol.hammingWeight(2147483645) << endl;  // expects 30

    return 0;
}
