#include <iostream>
#include <limits.h>
#include <numeric>
#include <algorithm>

using namespace std;
class Solution {
    public:
        int nthMagicalNumber(int n, int a, int b) {
            const long long MOD = 100000000 + 7;

            long long A = a;
            long long B = b;
            long long lcm = (A/gcd(A, B))*B;

            long long low = min(A,B);
            long long high = (long long)n*min(A,B);
            long long ans = high;

            while(low <= high)
            {
                long long mid = low + (high - low)/2;
                if (getcount(A,B,lcm,mid) >= n)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            return (int)(ans%MOD);
        }
    private:
        long long getcount(long long a, long long b, long long lcm, long long x)
        {
            return x/a + x/b - x/lcm;
        }
};

int main()
{
    Solution sol;
    int n1 = 1, a1 = 2, b1 = 3;
    cout << sol.nthMagicalNumber(n1,a1,b1) << endl;   //expects 2
    int n2 = 4;
    cout << sol.nthMagicalNumber(n2,a1,b1) << endl;   //expects 6

    return 0;
}
