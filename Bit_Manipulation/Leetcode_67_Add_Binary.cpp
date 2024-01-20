/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
    Input: a = "11", b = "1"
    Output: "100"

Example 2:
    Input: a = "1010", b = "1011"
    Output: "10101"

### Constraints:
    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.
*/

// Considering str1.length() < str2.length()

class Solution {
public:
    string addBinary(string a, string b) {

        if (a.length() > b.length())
            return addBinary(b,a);

        int pad = b.length() - a.length();
        string padding;
        //pad zeros to shorter string
        for (int i = 0; i < pad; i++)
            padding.push_back('0');

        a = padding + a;
        string res;

        char carry = '0';

        for (int i = a.length() - 1 ; i >=0; i--)
        {
            if (a[i] == '1'  && b[i] == '1')
            {
                if(carry == '1')
                {
                    res.push_back('1');
                    carry = '1';
                }
                else
                {
                    res.push_back('0');
                    carry = '1';
                }
            }
            else if (a[i] == '0' && b[i] == '0')
            {
                if (carry == '1')
                {
                    res.push_back('1');
                    carry = '0';
                }
                else
                {
                    res.push_back('0');
                    carry = '0';
                }
            }
            else if (a[i] != b[i])
            {
                if (carry == '1')
                {
                    res.push_back('0');
                    carry = '1';
                }
                else
                {
                    res.push_back('1');
                    carry = '0';
                }
            }
        }

        if (carry == '1')
            res.push_back(carry);

        //reverse the string
        reverse(res.begin(), res.end());

        //remove leading zeros
        int i = 0;
        while (i + 1 < res.length() && res[i] == '0')
           i++;
           
        return (res.substr(i));

    }
          
};