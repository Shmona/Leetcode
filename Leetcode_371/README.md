# Problem Statement : Sum of Two Integers

Given two integers a and b, return the sum of the two integers without using the operators + and -.

**Example 1:**

    Input: a = 1, b = 2
    Output: 3

**Example 2:**

    Input: a = 2, b = 3
    Output: 5
 
## Constraints:
- -1000 <= a, b <= 1000

## Approach:
**IDEA** :  using concept of half adder
- Truth Table 

        A  B | Sum  Carry
        -----------------
        0  0 |  0     0
        0  1 |  1     0
        1  0 |  1     0
        1  1 |  0     1
            
- Sum   = A ⊕ B   (XOR operation)
- Carry = A ⋅ B    (AND operation)

### Recursive :  TC = O(W)  = SC  , W is bit width ( 32 for integers )
- Solution Link :  https://leetcode.com/problems/sum-of-two-integers/submissions/1943767028/

    - compute sum = a ^ b (add without carry)
    - compute carry = (a & b)  (compute carry)
    - if carry != 0 :  recusively call getSum( sum,  carry << 1 )
    - return sum as answer

### Iterative : TC = O(W) ,  W is bit width ( 32 for integers ) ,  SC = O(1)  
- Solution Link :  https://leetcode.com/problems/sum-of-two-integers/submissions/1943776740/

- while b != 0 :
  
        compute sum = a ^ b (add without carry)
        compute carry = (a & b)  (compute carry)
        update a as sum and b as shifted carry (carry << 1)

- return a as answer
