/*
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

Example 1:
    Input: mat = [[1,2,3],
                [4,5,6],
                [7,8,9]]
    Output: 25

Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.


### Constraints:
    n == mat.length == mat[i].length //Square Matrix
    1 <= n <= 100
    1 <= mat[i][j] <= 100
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if ( n == 1)
        {
            return mat[0][0];
        }
        
        int D1 = 0, D2 = 0;
        for(int i = 0; i< n; i++)
        {
            for ( int j = 0; j < n; j++)
            {
                // Condition for principal diagonal
                if (i == j)
                    D1 += mat[i][j];
     
                // Condition for secondary diagonal
                if ((i + j) == (n - 1))
                    D2 += mat[i][j];
            }
        }
        if ( n%2 != 0)
            return (D1 + D2 - mat[n/2][n/2]);
        else
            return (D1 + D2);
        
    }
};