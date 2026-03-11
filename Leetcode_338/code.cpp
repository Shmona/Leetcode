#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Naive Solution
    vector<int> countBits(int n) {

        vector<int> res (n+1, 0);

        for (int i = 1; i <= n; i++)
            res[i] = bitcount(i);
        
        return res;
    }
    //using DP (Lowest-set-bit)
    vector<int> countBits_DP(int n) {
        vector<int> res (n + 1, 0);

        for (int i = 1 ; i <= n; i++)
            res[i] = res[i & (i - 1)] + 1;
        return res;
    }
    //using Shift DP
    vector<int> countBits_SDP(int n) {
        vector<int> res (n + 1, 0);

        for (int i = 1 ; i <= n; i++)
            res[i] = res[i >> 1] + (i & 1);
        
            return res;
    }
private:
    int bitcount(int n)
    {
        int ans = 0;
        while (n)
        {
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> res = sol.countBits(5);  // expects {0  1  1  2  1  2}
    cout << " \n Result is :  ";
    for (auto x : res)
        cout << x << "  ";

    vector<int> res1 = sol.countBits(0);  // expects {0}
    cout << " \n Result is :  ";
    for (auto x : res1)
        cout << x << "  ";

    vector<int> res3 = sol.countBits_DP(5);   // expects {0  1  1  2  1  2}
    cout << " \n Result is :  ";
    for (auto x : res3)
        cout << x << "  ";

    vector<int> res4 = sol.countBits_DP(2);   // expects {0  1  1 }
    cout << " \n Result is :  ";
    for (auto x : res4)
        cout << x << "  ";


    vector<int> res5 = sol.countBits_SDP(5);   // expects {0  1  1  2  1  2}
    cout << " \n Result is :  ";
    for (auto x : res5)
        cout << x << "  ";

    vector<int> res6 = sol.countBits_SDP(2);   // expects {0  1  1 }
    cout << " \n Result is :  ";
    for (auto x : res6)
        cout << x << "  ";
    
    return 0;
} 
