/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

NOTE :   You must write a solution in O(log(m * n)) time complexity.

Example 1:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

Example 2:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false
 
###Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= m, n <= 100
        -104 <= matrix[i][j], target <= 104
*/

/*NAIVE APPROACH
    Time complexity = max(O(m), O(n))
    Space complexity = O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        for ( int i = 0 ; i < m; i++)
        {
            if ( target >= matrix[i][0] && target <= matrix[i][n-1] )
            {
                for (int j = 0; j < n; j++)
                {
                    if( target == matrix[i][j])
                        return true;
                }
            }
        }
        return false; 
    }
};

/* USING BINARY SEARCH
    Time complexity = O(mlog(n))
    Space complexity = O(1)
*/

class Solution {
public:
    bool binary_search( vector<int>& mat, int n, int x)
    {
        int l = 0;
        int r = n - 1;
        while( l <= r) 
        {
            int mid = l + (r - l)/2;
            // Check if x is present at mid
            if (mat[mid] == x)
                return true;
            // If x greater, ignore left half
            if (mat[mid] < x)
                l = mid + 1;
            // If x is smaller, ignore right half
            else
                r = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();
        for ( int i = 0; i < m; i++)
        {
            if ( target >= matrix[i][0] && target <= matrix[i][n-1] )
            {
                return (binary_search(matrix[i], n, target));
            }
        }
        return false; 
    }
};
