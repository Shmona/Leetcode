/*
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:
    Input: matrix = [[1,2,3],[4,5,6]]
    Output: [[1,4],[2,5],[3,6]]
    

### Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 1000
        1 <= m * n <= 105
        -109 <= matrix[i][j] <= 109
*/
/*
Time Complexity = O(m*n) = Space Complexity
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int m = matrix.size();     // Original row
        int n = matrix[0].size();  // Original column

        vector<vector<int>> res(n,vector<int> (m));
        for ( int i = 0, r = 0 ; i < m , r < n; i++, r++)
        {
            for ( int j = 0, c = 0; j < n, c < m; j++, c++)
                res[r][c] = matrix[j][i]; 
        }
        return res;   
    }
};