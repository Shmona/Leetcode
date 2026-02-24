
# Problem Statement :  Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

**Example 1:**

    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.

**Example 2:**

    Input: nums1 = [1,2], nums2 = [3,4]
    Output: 2.50000
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

## Constraints:
- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -10^6 <= nums1[i], nums2[i] <= 10^6

## Approach 
### Naive Approach : Two-pointer approach (Full merging) TC = O(m + n), SC = O(m + n)
- Solution Link : https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/1923419741/
  
- Merge the two sorted arrays into a new sorted array merge of length l = m + n
- Compute the median from merge array

### Optimal Solution : Binary Search approach TC = O(log(min(m,n))), SC = O(1)
- Solution Link :  https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/1923528551/
  
- Ensure first array(A) is smaller in size than second one(B)

- Partition A and B into left and right parts
        Left parts: A[0..i-1] and B[0..j-1]
        Right parts: A[i..m-1] and B[j..n-1]

        such that,
        1.  Left has half the elements i.e (m+n+1)/2 no. of elements 
            so,  i + j = m + n + 1
        2. All left elements ≤ all right elements
            Aleft <= Bright
            Bleft <= Aright 
    
- Binary search i  in A (low = 0 , high = m):  
    - while low <= high :
      
          :   i = mid point,  j = (m+n+1)/2  − i 
          :   Aleft => A[i-1] , Aright => A[i] 
          :   Bleft => B[j-1] , Bright => B[j]
  
          =>  If Aleft > Bright → i is too far right → move left  → high = i - 1
          =>  Else if Bleft > Aright → i is too far left → move right → low = i + 1
          =>  Else → perfect partition found 
                          :  If total length is odd → median is max(Aleft, Bleft)
                          :  If even → median is average of max(Aleft,Bleft) and min(Aright,Bright)

 
