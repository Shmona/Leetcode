# Problem Statement :  Nth Magical Number

A positive integer is magical if it is divisible by either a or b.
Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 10^9 + 7.

**Example 1:**

    Input: n = 1, a = 2, b = 3
    Output: 2

**Example 2:**

    Input: n = 4, a = 2, b = 3
    Output: 6
    
## Constraints:
- 1 <= n <= 10^9
- 2 <= a, b <= 4 * 10^4

## Approach:
**IDEA**

- For a given number x, how many magical numbers are ≤ x?
- Apply binary search for the smallest x such that:  count(x) ≥ n

**Logic behind Counting magical numbers ≤ x**
Let:
    M_a(x) = number of multiples of a ≤ x = ⌊x/a⌋
    M_b(x) = number of multiples of b ≤ x = ⌊x/b⌋

- If we add them: ⌊x/a⌋ + ⌊x/b⌋ , but here we are double-counting numbers divisible by both a and b.
- Numbers divisible by both are multiples of lcm(a,b)
- so, 

        count(x) = ⌊x/a⌋ +  ⌊x/b⌋ − ⌊ x/lcm(a,b) ​⌋
        lcm(a,b) =  a⋅b / gcd(a,b)​


### Using Binary Search on answer :
- Solution Link : https://leetcode.com/problems/nth-magical-number/submissions/1935427419/

- count(x) is non-decreasing in x as ⌊x/a⌋, ⌊x/b⌋ and ⌊x/lcm(a,b)⌋ are non-decreasing as x increases
- Apply binary search in the range  [ low , high ] , low = min(a,b),  high =  n * min(a,b)
- while low <= high :
        
            =>  compute mid and treat it as x and compute count(x)
            =>  if count(x) >=  n :  x could be the possible answer so store it as ans and keep looking left for smallest answer possible.
            =>  if count(x) <  n  :  discard that half (left)  and serach in other half (right)

         Caution :  to avoid overflow use long long as intermediate datatype 

- return ans as integer after applying modulo 10^9 + 7 

        
