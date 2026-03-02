# Problem Statement : Count Negative Numbers in a Sorted Matrix
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

**Example 1:**

    Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    Output: 8
    Explanation: There are 8 negatives number in the matrix.

**Example 2:**

    Input: grid = [[3,2],[1,0]]
    Output: 0
 
## Constraints:
- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- -100 <= grid[i][j] <= 100
 
    Follow up: Could you find an O(n + m) solution?

## Approach:
### Naive Solution :  TC = O(row*col) , SC = O(1)
- Solution Link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/1934470342/

- Traverse the given matrix row-wise from left to right
- keep counting the no. of negative numbers
- return count 

### Straicase (top-right) search : TC = O(row + col), SC = O(1) 
- Solution Link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/1935378310/

- Starts from top-right element => grid[0][col-1] i.e i = 0 , j = col - 1
- while i < row && j >= 0 :

        => if grid[i][j]  < 0 :  All elements in this column are negative count += (row - i) and move to next column j--
        => else : move to next row , i++

### Straicase (bottom-left) search : TC = O(row + col), SC = O(1) 
- Solution Link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/1935380204/

- Starts from bottom-left element => grid[row - 1][0] i.e i = row - 1 , j = 0
- while i >= 0 && j < col :

        => if grid[i][j]  < 0 :  All elements in this row  are negative count += (col - j) and move to next row i--
        => else : move to next column, j++


### Binary Solution per row: TC = (m Log n) , SC = O(1)
- Solution Link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/1934492850/

-  Traverse through matrix row-wise
-  check first element of rach row
  
        - if its negative : all elements in that row will be negative so count += Column_size
        - else apply binary search on that row to get the index of first negative element (caution:  index == Column_size, if there are no negative elements)
        - add count += (Column_size - index)
        
- return count
