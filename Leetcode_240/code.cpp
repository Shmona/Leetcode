#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        // straicase top-right search TC = O(row + col), SC = O(1)
        bool searchMatrix_TR(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            int col = matrix[0].size();

            int r = 0, c = col-1;
            while ( r < row && c >= 0)
            {
                if (matrix[r][c] == target)
                    return true;
                else if (matrix[r][c] < target)
                    r++;
                else
                    c--;
            }
            return false;
       }
        // straicase left-bottom search TC = O(row + col), SC = O(1)
        bool searchMatrix_LB(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            int col = matrix[0].size();

            int r = row - 1, c = 0;
            while ( r >= 0 && c < col)
            {
                if (matrix[r][c] == target)
                    return true;
                else if (matrix[r][c] < target)
                    c++;
                else
                    r--;
            }
            return false;
        }
         // Binary Search per row TC = O(row Log(col)), SC = O(1)
        bool searchMatrix_BS(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            int col = matrix[0].size();

            for (int i = 0 ; i < row; i++)
            {
                if (target > matrix[i][col - 1] || target < matrix[i][0] )
                    continue;
                
                int low = 0 , high = col-1;
                while (low <= high)
                {
                    int mid = low + (high - low)/2;
                    if ( target == matrix[i][mid])
                        return true;
                    else if (target > matrix[i][mid] )
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
            return false;
        }

};

int main()
{
    Solution sol;
    vector<vector<int>> v1 = {{1,4,7,11,15},
                             {2,5,8,12,19},
                             {3,6,9,16,22},
                             {10,13,14,17,24},
                             {18,21,23,26,30}};

    int t1 = 5;
    cout << sol.searchMatrix_LB(v1, t1) << endl;   //expects true
    cout << sol.searchMatrix_TR(v1, t1) << endl;
    cout << sol.searchMatrix_BS(v1, t1) << endl;

    vector<vector<int>> v2 = {{1,4},{2,5}};
    int t2 = 2;
    cout << sol.searchMatrix_LB(v2, t2) << endl;   //expects true
    cout << sol.searchMatrix_TR(v2, t2) << endl;
    cout << sol.searchMatrix_BS(v2, t2) << endl;

    int t3 = 20;
    cout << sol.searchMatrix_LB(v1, t3) << endl;   //expects false
    cout << sol.searchMatrix_TR(v1, t3) << endl;
    cout << sol.searchMatrix_BS(v1, t3) << endl;

    return 0;
}
