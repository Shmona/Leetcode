/*
Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, 
it is the product of some integer with itself.
You must not use any built-in library function, such as sqrt.

Example 1:
    Input: num = 16
    Output: true
    Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Example 2:
    Input: num = 14
    Output: false
    Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

###Constraints:
    1 <= num <= 2^31 - 1
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if ( num == 1)
            return true;
        
        int l = 2 , r = num;
        int mid = 0;

        while (r >= l)
        {
            mid = l + (r - l)/2;
            if (num%mid == 0 && mid == num/mid)
                return true;
            else if (mid  > num/mid)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};