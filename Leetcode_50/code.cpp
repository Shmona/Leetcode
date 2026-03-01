#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution{
    public:
        double myPow(double x, int n)
        {
            long long exponent = n;
            if (exponent < 0)
            {
                x = 1.0/x;
                exponent = -exponent;
            }

            double ans = 1.0;
            while (exponent > 0)
            {
                if (exponent & 1)
                    ans *= x;

                x *= x;
                exponent >>= 1;
            }
            return ans;
        }
};

int main()
{
    Solution sol;
    double x1 = 2;
    int n1= -2;
    cout << fixed << sol.myPow(x1, n1) << endl;  //expects  0.250000

    double x2 = 2;
    int n2 = 10;
     cout << fixed << sol.myPow(x2, n2) << endl;  //expects  1024.000000
     
    return 0;
}
