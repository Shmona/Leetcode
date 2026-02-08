#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    // Approach 1 : TC = O(N) = SC
    string removeDuplicates(string s) {
        int l = s.length();

        if (l == 1)
            return s;
        
        string res;
        int i = 0;

        while (i < l)
        {
            if (!res.empty() && res.back() == s[i])
                res.pop_back();
            else
                res.push_back(s[i]);
            i++;
        }
        return res;
    }

    // Approach 2 :  using stack : TC = O(N) = SC
    string removeDuplicates_stack(string s) {  
        stack<char> st;
        
        for (char x : s)
        {
            if (!st.empty() && st.top() == x)
                st.pop();
            else
                st.push(x);
        }
        string res;
        //Reserve capacity to avoid reallocations
        res.reserve(st.size());
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.removeDuplicates("abbaca") << endl;    // expects "ca"
    cout << sol.removeDuplicates_stack("abbaca") << endl;

    cout << sol.removeDuplicates("a") << endl;    // expects "a"
    cout << sol.removeDuplicates_stack("a") << endl; 

    cout << sol.removeDuplicates("azxxzy") << endl;    // expects "ay"
    cout << sol.removeDuplicates_stack("azxxzy") << endl;

    return 0;
}
