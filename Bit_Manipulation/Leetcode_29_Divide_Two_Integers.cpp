/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be 
truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: 
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: 
[−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and 
if the quotient is strictly less than -231, then return -231.

### Constraints:
    -231 <= dividend, divisor <= 231 - 1
    divisor != 0

*/

/*Naive Approach
    Time Complexity : O(log2N)
    Space Complexity : O(1)
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int sign = (dividend < 0 ) ^ (divisor < 0) ? -1 : 1;
        
        long count = 0;
        long  div = abs(divisor);
        long  divi = abs(dividend);

        if ( div == 1)
            return (sign *divi);

        while (divi >= div)
        {
            long k = 1;
            while ( k* 2*div <= divi)
                k = k *2;
            
            divi = divi - k*div;
            count = count+k;;
        }

        return (sign *count);
    }
};

/*
# Most Efficient
    Time Complexity : O(1)
    Space Complexity : O(1)

## LOGIC
    a/b = c
    => log(a/b) = log(c)
    => log(a) - log(b) = log(c)
    => c = exp(log(a) - log(b)) + error_tolerance
    Here, error_tolerance = 0.0000000001
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int sign = (dividend < 0 ) ^ (divisor < 0) ? -1 : 1;
        
        long  div = abs(divisor);
        long  divi = abs(dividend);

        if ( div == 1)
            return (sign *divi);
        
        long count = exp(log(divi) - log(div)) + 0.0000000001;

        return (sign *count);
    }
};