/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
O NOT allocate another 2D matrix and do the rotation.

 
### Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[7,4,1],[8,5,2],[9,6,3]]

### Constraints:
    n == matrix.length == matrix[i].length
    1 <= n <= 20
    -1000 <= matrix[i][j] <= 1000
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());

        //transpose of matrix
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = i+1; j < matrix.size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        
    }
};