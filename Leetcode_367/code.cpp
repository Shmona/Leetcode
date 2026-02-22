#include <iostream>

using namespace std;
class Solution{
    public:
        bool isPerfectSquare(int num) {
            if(num == 1)
                return true;
            
            int low = 2, high = num;
            while(low <= high)
            {
                int mid = low + ( high - low )/2;
                if ( num%mid == 0 && mid == num/mid )
                    return true;
                else if ( mid < num/mid )
                    low = mid + 1;
                else    
                    high = mid - 1;
            }
            return false;
        }
};

int main()
{
    Solution sol;
    cout << sol.isPerfectSquare(16) << endl;  //expects true
    cout << sol.isPerfectSquare(10) << endl;  //expacts false
    cout << sol.isPerfectSquare(1) << endl;   //expacts true

    return 0;
}
