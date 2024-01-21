/*
Given an array arr of integers, check if there exist two indices i and j such that :

1.  i != j
2.  0 <= i, j < arr.length
3.  arr[i] == 2 * arr[j]
 
Example 1:
    Input: arr = [10,2,5,3]
    Output: true
    Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

Example 2:
    Input: arr = [3,1,7,11]
    Output: false
    Explanation: There is no i and j that satisfy the conditions.

###Constraints:
    2 <= arr.length <= 500
    -10^3 <= arr[i] <= 10^3
*/
/* NAIVE APPROACH
Time complexity = O(N^2)
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        for ( int i = 0; i < arr.size(); i++)
        {
            for ( int j = 0; j < arr.size(); j++)
            {
                if ((arr[i] == 2*arr[j]) && (i != j))
                    return true;
            }
        }
        return false;
    }
};

/*BETTER APPROACH
Time Complexity = O(Nlog(n))
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort (arr.begin(), arr.end());
        for ( int i = 0; i < arr.size(); i++)
        {
            int temp = 2*arr[i];
            int l = 0;
            int r = arr.size() - 1;

            while ( l <= r)
            {
                int mid = ( r + l )/2;
                if ((arr[mid] == temp) && (i != mid) )
                    return true;
                else if (arr[mid] < temp)
                    l++;
                else
                    r--;
            }
        }
        return false;
    }
};