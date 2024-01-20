/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
    Input: n = 3
    Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
    Input: n = 1
    Output: [[1]]
 
### Constraints:
    1 <= n <= 20
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> mat(n , vector<int> (n));
        int r1 = 0 , c1 = 0;
        int r2 = n-1, c2 = n -1;
        int k = 1;
        while (k <= n*n)
        {
            for (int j = c1 ; j <= c2 && k <= n*n; j++)
                mat[r1][j] = k++;

            for (int i = r1+1; i <= r2-1 && k <= n*n; i++)
                mat[i][c2] = k++;

            for (int j = c2; j >= c1 && k <= n*n; j--)
                mat[r2][j]= k++;

            for (int i = r2 - 1; i >= r1 + 1 && k<=n*n; i--)
                mat[i][c1] = k++;
            r1++, c1++, r2--, c2--;
        } 
        return mat;
    }
};