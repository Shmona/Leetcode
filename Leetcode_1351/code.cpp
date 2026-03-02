#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        // Naive Solution
        int countNegatives(vector<vector<int>>& grid) {

            int count = 0;
            for (auto row : grid)
            {
                for (auto col : row)
                {
                    if (col < 0)
                        count++;
                }
            }
            return count;
        }
        //  Stair-case (top - right) search
        int countNegatives_TR(vector<vector<int>>& grid) {

            int count = 0;
            int row = grid.size();
            int col = grid[0].size();

            int  i = 0 , j = col - 1;

            while(i < row && j >= 0) 
            {
                if (grid[i][j] < 0)
                {
                    count += (row - i);
                    j--;
                }
                else
                    i++;
            }
            return count;
        }

        //  Stair-case (bottom - left) search
        int countNegatives_BL(vector<vector<int>>& grid) {

            int count = 0;
            int row = grid.size();
            int col = grid[0].size();

            int  i = row - 1 , j = 0;

            while(i >= 0 && j < col) 
            {
                if (grid[i][j] < 0)
                {
                    count += (col - j);
                    i--;
                }
                else
                    j++;
            }
            return count;
        }

        // Binary Solution
        int countNegatives_BS(vector<vector<int>>& grid) {

            int count = 0;
            int row = grid.size();
            int col = grid[0].size();

            for (int i = 0; i < row; i++)
            {
                if (grid[i][0] < 0)
                    count += col;
                else
                {
                    int index = binarySearch(grid[i], 0, col - 1);
                    count += (col - index);
                }
            }
            return count;
        }
    private:
        int binarySearch(vector<int>& Row, int low, int high)
        {
            int ans = Row.size();
            while(low <= high)
            {
                int mid = low + (high - low)/2;
                if (Row[mid] < 0)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            return ans;
        }
};

int main()
{
    Solution sol;
    vector<vector<int>> v1 = {  {4,3,2,-1},
                                {3,2,1,-1},
                                {1,1,-1,-2},
                                {-1,-1,-2,-3}   };

    cout << sol.countNegatives(v1) << endl;   // expects  8
    cout << sol.countNegatives_TR(v1) << endl;
    cout << sol.countNegatives_BL(v1) << endl;
    cout << sol.countNegatives_BS(v1) << endl;  

    vector<vector<int>> v2 = {  {3,2},
                                {1,0}   };

    cout << sol.countNegatives(v2) << endl;   // expects  0
    cout << sol.countNegatives_TR(v2) << endl;
    cout << sol.countNegatives_BL(v2) << endl;
    cout << sol.countNegatives_BS(v2) << endl;  
                                
    return 0;
}
