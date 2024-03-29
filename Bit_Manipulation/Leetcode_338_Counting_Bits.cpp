/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
ans[i] is the number of 1's in the binary representation of i.

Example 1:
    Input: n = 2
    Output: [0,1,1]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10

Example 2:
    Input: n = 5
    Output: [0,1,1,2,1,2]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10
    3 --> 11
    4 --> 100
    5 --> 101
 

### Constraints:
    0 <= n <= 105
*/

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> res (n+1, 0);
        if( n== 0)
        {
            res[0] = 0;
            return res;
        }

        if (n == 1)
        {
            res[1] = 1;
            return res;
        }
        res[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            res[i] = i & 1 ? (res[i / 2] + 1 ) : res[i / 2];
        }
        return res;
            
    }
};