#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = s.length();
        vector<int> index(26, 0);

        int left = 0;
        int max_count = 0, ans = 0;
        for ( int right = 0; right < l; right++)
        {
            int temp = s[right] - 'A';
            index[temp]++;
            
            max_count = max(max_count, index[temp]);
            while (right - left + 1 - max_count > k)
            {
                index[s[left] - 'A']--;
                left++;
            }  
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    string s = "AABABBA";
    int k = 1;
    Solution sol;

    cout << sol.characterReplacement(s, k) << endl;  //expects 4
    string s1 = "ABAB";
    int k1 = 2;
    cout << sol.characterReplacement(s1, k1) << endl;  //expects 4
    
    return 0;
}
