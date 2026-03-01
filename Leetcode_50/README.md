# Problem Statement :  Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

**Example 1:**

    Input: x = 2.00000, n = 10
    Output: 1024.00000

**Example 2:**

    Input: x = 2.10000, n = 3
    Output: 9.26100

**Example 3:**

    Input: x = 2.00000, n = -2
    Output: 0.25000
    Explanation: 2-2 = 1/22 = 1/4 = 0.25
 
## Constraints:

- -100.0 < x < 100.0
- -2^31 <= n <= 2^31-1
- n is an integer.
- Either x is not zero or n > 0.
- -10^4 <= x^n <= 10^4

## Approach:
### Using  Binary-search-like reduction : TC = O(Log |n|) , SC = O(1)
- Solution Link:  https://leetcode.com/problems/powx-n/submissions/1934414201/

- If n is even:  x^n = (x^2)^(n/2) 

- If n is odd:   x^n = x * x^(n−1)

- If n < 0:  x^n = 1 / (x^n)

- Special case: n = INT_MIN (-2^31)  :  Negating it overflows a 32-bit int so store n in long long.

- At each step:

    - halve n (n = n/2)
    - square x (x = x*x)
    - if n was odd, multiply result by current x

