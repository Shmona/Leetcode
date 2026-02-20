# Problem Statement 
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

**Example 1:**

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

**Example 2:**

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false
    
## Constraints:
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 100
- -10^4 <= matrix[i][j], target <= 10^4

## Approach 
### Naive approach : TC = O(row * col), SC= O(1)
- Traverse the matrix row-wise and return true if target is found

### Binary Search approach over each row : TC = O(row + log(col)), SC= O(1)
- Traverse the matrix row-wise
- apply binary search on the row if target lies in that row

### Binary Search approach over flatten matrix : TC = O(log (m * n)), SC= O(1)
- Apply binary search on the flatten matrix 
- maintain two pointer low => 0 and high => row*col - 1
- while  low <= high :

        => compute mid 
        => compute row index r = mid/col 
        => compure col index c = mid%col
        => if target == matrix[r][c]   :  return true
        => if target < matrix[r][c]  : target lies in lower half , move the high pointer to mid - 1
        => if target > matrix[r][c]  : target lies in upper half , move the low pointer to mid + 1
