/*
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:
    Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
    Output: [15]
    Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 2:
    Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
    Output: [12]
    Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 3:
    Input: matrix = [[7,8],[1,2]]
    Output: [7]
    Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

### Constraints:
        m == mat.length
        n == mat[i].length
        1 <= n, m <= 50
        1 <= matrix[i][j] <= 105.
        All elements in the matrix are distinct.
*/

/*
Time Complexity = O (m * n)
Space Complexity = O(m) + O(n)
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();     // row
        int n = matrix[0].size();  // column

        vector<int> row_min(m, 0);
        vector<int> col_max(n, 0);

        for (int i = 0 ; i < m; i++)
        {
            row_min[i] =  matrix[i][0];
            for ( int j = 0 ; j < n; j++)
            {
                row_min[i] = min(row_min[i], matrix[i][j]);
            } 
        }

        for (int j = 0 ; j < n; j++)
        {
            col_max[j] = matrix[0][j];
            for ( int i = 0 ; i < m; i++)
            {
                col_max[j] = max(col_max[j], matrix[i][j]);
            } 
        }

        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (row_min[i] == matrix[i][j] && matrix[i][j] == col_max[j])
                    res.push_back(row_min[i]);
            }
        }
        return res;
    }
};