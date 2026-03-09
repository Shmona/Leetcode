# Problem Statement :  Single Number
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

**Example 1:**

    Input: nums = [2,2,1]
    Output: 1

**Example 2:**

    Input: nums = [4,1,2,1,2]
    Output: 4

**Example 3:**

    Input: nums = [1]
    Output: 1

## Constraints:

- 1 <= nums.length <= 3 * 10^4
- -3 * 10^4 <= nums[i] <= 3 * 10^4
- Each element in the array appears twice except for one element which appears only once.

## Apporach :
**IDEA** :    XOR Ops property 
- Truth Table
        
        0 ⊕ 0 = 0
        0 ⊕ 1 = 1
        1 ⊕ 0 = 1
        1 ⊕ 1 = 0

- Core Properties
1. Identity   :   A ⊕ 0 = A    =>  (XOR with 0 leaves the value unchanged)

2. Self‑Inverse :  A ⊕ A = 0   =>  (A value XORed with itself results in 0)

3. Commutative :  A ⊕ B = B ⊕ A   =>   (Order of operands does not matter) 

4. Associative :  (A ⊕ B) ⊕ C = A ⊕ (B ⊕ C)  =>  (Grouping does not affect the result) 

5. Bit Toggle :  A ⊕ 1 = NOT A   =>  (bitwise :  XOR with 1 flips the corresponding bit).

7. Parity Property

        XOR of multiple bits is 1 if the number of set bits is odd
        XOR is 0 if the number of set bits is even

### using bit manipulation : TC = O(N) , SC = O(1)
- Solution Link :  https://leetcode.com/problems/single-number/submissions/1942708139/

- Traverse array from left to right and keep xoring each element.
- Since each element appears twice so their xored will be zero (as per  Self‑Inverse property  A ⊕ A = 0)  and only single number will remain as xored result. 
