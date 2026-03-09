#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;

        while (num > 0)
        {
            if (num & 1)
                num--;
            else
                num >>= 1;
            count++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    cout << sol.numberOfSteps(13) << endl;    // expects 6
    cout << sol.numberOfSteps(123) << endl;   // expects 12
    cout << sol.numberOfSteps(0) << endl;     // expects 0
    cout << sol.numberOfSteps(-2) << endl;    // expects 0

    return 0;
}
