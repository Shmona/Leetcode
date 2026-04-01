#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> res;
        unordered_map<int, string> m = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        
        string curr;
        mapping(digits, 0, m, curr, res);

        return res;
    }
private:
void mapping(string &digits, int index, const unordered_map<int, string>& m,
                 string& curr, vector<string> & res)
    {

        if (index == (int)digits.size()) 
        {
            res.push_back(curr);
            return;
        }

        int key = digits[index] - '0';
        const string& letters = m.at(key);
        for (char c : letters) 
        {
            curr.push_back(c);
            mapping(digits, index + 1, m, curr, res);
            curr.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    string s1 = "23";
    vector<string> res = sol.letterCombinations(s1);  // expects {"ad","ae","af","bd","be","bf","cd","ce","cf"}
    cout << " \n Letter Combination for " << s1 << " :  ";
    for (auto x : res)
        cout << x << "  ";

    
    string s2 = "236";
    cout << " \n Letter Combination for " << s2 << " :  ";
    vector<string> res1 = sol.letterCombinations(s2);  

    for (auto x : res1)
        cout << x << "  ";
    return 0;
}
