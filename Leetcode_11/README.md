Given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
 
##Constraints:
    n == height.length
    2 <= n <= 10^5
    0 <= height[i] <= 10^4


IDEA:
===================

Area = min(height[left],height[right]) *  (right−left)

To maximize the area of the rectangle formed by two lines:
1.  Maximize the width
        :  width =  distance between two indices.
        :  To get the maximum width, start by choosing lines that are farthest apart (leftmost and rightmost).

2.  Maximize the limiting height
        : height of the rectangle is determined by the smaller of the two selected heights.
        : To increase the area  =>  try to increase the minimum height even if the width decreases.

Approach 1 : Two pointer 
==============================
TC = O(n)
SC = O(1)

psuedo code:
1.  init two varibles pointing to index of last (right) and first element (left) in the array
2.  iterate over each element and compute  temp_area =  min(arr[left], arr[right]) *(right - left)
3.  store max of temp_area as res = max(res, temp_area)
4.  move to pointer whichever is accounted in computation of temp_area
        : if arr[left] < arr[right]  then left++;
        : else right--;
5.  return res

Approach 2 : Greddy algo 
==============================
TC = O(n)
SC = O(1)

psuedo code:
1.  init two varibles pointing to index of last (right) and first element (left) in the array
2.  compare the elements arr[right] & arr[left] 
                : whichever is smaller account it for computation as temp_area = smaller_one * (right - left)
                        : if its left element => temp_area = arr[left]* (right - left) and left++
                        : if its right element => temp_area = arr[right]* (right - left) and right--
                : if both are equal 
                        : temp_area = arr[left]* (right - left) and left++, right--

3. store max of temp_area as res = max(res, temp_area)
4. Repeat 2, & 3 till (right > left)
5. return res


