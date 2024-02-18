/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:
    Input: num = 38
    Output: 2
    Explanation: The process is
    38 --> 3 + 8 --> 11
    11 --> 1 + 1 --> 2 
    Since 2 has only one digit, return it.

Example 2:
    Input: num = 0
    Output: 0

###Constraints:
0 <= num <= 2^31 - 1

Follow up: Could you do it without any loop/recursion in O(1) runtime?
*/
//RECURSIVE APPROACH
class Solution {
public:
    int addDigits(int num) {

        int sum = 0;
        while (num)
        {
            sum += num%10;
            num = num/10;
        }
        if (sum < 10)
            return sum;
        else
            return addDigits(sum);
    }
};

//ITERATIVE APPROACH
class Solution {
public:
    int addDigits(int num) {
        while (num > 9)
        {
            int temp = num;
            int sum = 0;
            while(temp)
            {
                sum += temp%10;
                temp = temp/10;
            }
            num = sum;
        }
        return num;
    }
};

// OPTIMAL SOLUTION :  Based on divisibility by 9
class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        else if (num%9 == 0)
            return 9;
        else
            return num%9;
    }
};