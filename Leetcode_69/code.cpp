#include <iostream>

using namespace std;
class Solution{
    public:
        int mySqrt(int x){
            if (x == 0)
                return 0;

            int low = 1, high = x;
            while (low <= high)
            {
                int mid = low + (high - low)/2;
                if (mid == x/mid)
                    return mid;
                else if ( mid > x/mid)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return high;
        }
};

int main()
{
    Solution sol;
    cout << sol.mySqrt(10) << endl;  //expects 3
    cout << sol.mySqrt(8) << endl;  //expects  2
    cout << sol.mySqrt(4) << endl;  //expects  2
    return 0;
}
