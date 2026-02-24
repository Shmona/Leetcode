# Problem Statement :  Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 
**Example 1:**

    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
    Output: true

**Example 2:**

    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
    Output: false
 
## Constraints:

- m == matrix.length
- n == matrix[i].length
- 1 <= n, m <= 300
- -10^9 <= matrix[i][j] <= 10^9
- All the integers in each row are sorted in ascending order.
- All the integers in each column are sorted in ascending order.
- -10^9 <= target <= 10^9

## Approach 
### straicase top-right search TC = O(row + col), SC = O(1)
- Solution Link : https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/1926660196/
  
- starts from top-right element => matrix[0][col-1]  i.e r = 0 , c = col - 1
- while  r < row  && c >= 0 :

      => if matrix[r][c] == target : Target is found, return true.
      => if matrix[r][c] <  target : Target can't be in the search row to move to next (down) row.  => r++
      => if matrix[r][c] >  target : Target can be in the search row to move to next element in searched row. => c--


### straicase left- bottom search TC = O(row + col), SC = O(1)
- Solution Link : https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/1926662719/
  
- starts from left-bottom element => matrix[row-1][0]  i.e r = row - 1 , c = 0
- while  r >= 0  && c < col :

      => if matrix[r][c] == target : Target is found, return true.
      => if matrix[r][c] <  target : Target can be in the search row to move to next eleement in searched row.  => c++
      => if matrix[r][c] >  target : Target can't be in the search row to move to next (up) row. => r--

### Binary Search per row TC = O(row Log(col)), SC = O(1)
- Solution Link : https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/1926694528/

- traverse the matrix per row, i => 0 to row - 1

      - if target > matrix[i][col-1]  or target < matrix[i][0]   :  skip this row
      - otherwise do binary search over the row elements, low = 0 , high = col- 1
          - while low <= high :
              => compute mid and compare matrix[i][mid] with target
              => target == matrix[i][mid] : Target is found, return true.
              => target > matrix[i][mid] : move the low pointer to mid + 1
              => target < matrix[i][mid] : move the high pointer to mid - 1

