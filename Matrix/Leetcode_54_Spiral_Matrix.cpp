/*
Given an m x n matrix, return all elements of the matrix in spiral order.

### Example 1:
        Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [1,2,3,6,9,8,7,4,5]

### Example 2:
        Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
        Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

### Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 10
        -100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size(); // row
        int n = matrix[0].size(); //col

        vector<int> res(m*n , 0);
        int r1 = 0 , c1 = 0;
        int r2 = m-1, c2 = n -1;
        int k = 0;
        while (k < m*n)
        {
            for (int j = c1 ; j <= c2 && k < m*n; j++)
                res[k++] = matrix[r1][j];

            for (int i = r1+1; i <= r2-1 && k < m*n; i++)
                res[k++] = matrix[i][c2];

            for (int j = c2; j >= c1 && k < m * n; j--)
                res[k++] = matrix[r2][j];

            for (int i = r2 - 1; i >= r1 + 1 && k < m * n; i--)
                res[k++] = matrix[i][c1];
            r1++, c1++, r2--, c2--;
        } 
        return res;
    }
};