/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, 
return the number of negative numbers in grid.

Example 1:
    Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    Output: 8
    Explanation: There are 8 negatives number in the matrix.

Example 2:
    Input: grid = [[3,2],[1,0]]
    Output: 0
 
###Constraints:
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 100
        -100 <= grid[i][j] <= 100

Follow up: Could you find an O(n + m) solution?
*/
/* NAIVE APPROACH
Time Complexity = O(m*n)
Space Complexity = O(1)
*/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0 ; i < m; i++)
        {
            for ( int j = 0; j < n; j++)
                if(grid[i][j] < 0)
                    count++;
        }
        return count;
    }
};
/* BETTER APPROACH : Using Binary Search
Time Complexity = O(mlog(n))
Space Complexity = O(1)
*/
class Solution {
public:
    int binarysearchPerRow(vector<int>&row)
    {
        int r = row.size();
        int l = 0;
        int mid = 0;
        while ( l < r)
        {
            mid = l + (r -l)/2;
            if (row[mid] >= 0)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    int countNegatives(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0 ; i < m; i++)
        {
            int temp = binarysearchPerRow(grid[i]);
            count +=  (n - temp);
        }
        return count;
    }
};