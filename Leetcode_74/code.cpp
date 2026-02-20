#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        //Naive approach : TC = O(row * col), SC= O(1)
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            int col = matrix[0].size();

            for (int i = 0 ; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (matrix[i][j] == target)
                        return true;
                }
            }
            return false;
        }

        //Binary Search approach over each row : TC = O(row + log(col)), SC= O(1)
        bool searchMatrix_BSoverRow(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            int col = matrix[0].size();

            for ( int i = 0 ; i < row; i++)
            {
                if (target >= matrix[i][0] && target <= matrix[i][col-1])
                    return binarySearch(matrix[i], col, target);
            }
            return false;
        }

        //Binary Search approach over flatten matrix : TC = O(log (m * n), SC= O(1)
        bool searchMatrix_BSoverFlatten(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            int col = matrix[0].size();

            int low = 0, high = row * col - 1;

            while ( low <= high)
            {
                int mid = low + ( high - low )/2;
                int r = mid/col;
                int c = mid%col;
                if (matrix[r][c] == target)
                    return true;
                else if ( matrix[r][c] < target)
                    low =  mid + 1;
                else
                    high = mid - 1;
            }
            return false;
        }
    private:
        bool binarySearch(vector<int> row, int n, int target)
        {
            int low = 0 , high = n - 1;
            while ( low <= high )
            {
                int mid = low + ( high - low )/2;
                if (row[mid] == target)
                    return true;
                else if ( row[mid] < target )
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return false;
        }

};

int main()
{
    Solution sol;
    vector<vector<int>> v1 = {{1,3,5,7},
                                {10,11,16,20},
                                {23,30,34,60 }};
    int t1 = 3;
    cout << sol.searchMatrix(v1, t1) << endl;                  // expects true
    cout << sol.searchMatrix_BSoverRow (v1, t1) << endl;
    cout << sol.searchMatrix_BSoverFlatten(v1, t1) << endl;

    int t2 = 13;
    cout << sol.searchMatrix(v1, t2) << endl;
    cout << sol.searchMatrix_BSoverRow(v1, t2) << endl;      // expects false
    cout << sol.searchMatrix_BSoverFlatten(v1, t2) << endl;

    return 0;
}
