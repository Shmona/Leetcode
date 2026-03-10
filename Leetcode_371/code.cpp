#include <iostream>

using namespace std;
class Solution {
public:
    //Recursive 
    int getSum_recursive(int a, int b) {

        int sum = a ^ b;
        int carry = a & b;

        if (carry)
            return getSum_recursive(sum , carry << 1);
        return sum;
    }

    //Iterative 
    int getSum_iterative(int a, int b) {

        while ( b != 0 )
        {
            int sum = a ^ b;
            int carry = a & b;
            
            a = sum;
            b = carry << 1;
        }
        return a;
    }
};

int main()
{
    Solution sol;
    cout << sol.getSum_recursive(2,3) << endl;        //expects 5
    cout << sol.getSum_recursive(0, -100) << endl;    //expects -100

    cout << sol.getSum_iterative(2,3) << endl;
    cout << sol.getSum_iterative(0, -100) << endl;

    return 0;                       
}
