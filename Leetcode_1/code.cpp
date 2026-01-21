#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    // Naive approach : TC = O(N^2)  SC= O(1)
    vector<int> TwoSum(vector<int> &v , int target)
    {
        int n = v.size();
        for ( int i = 0 ; i < n -1; i++)
        {
            for ( int j = i+1; j < n; j++)
            {
                if (v[i] + v[j] == target)
                    return {i, j};
            }
        }
        return {-1,-1};
    }
    // Efficient approach : TC = O(N) =  SC
    vector<int> TwoSum2(vector<int> &v, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0 ; i < v.size(); i++)
        {
            if (m.find(target - v[i]) != m.end())
                return {i, m[target-v[i]]};
            m.insert({v[i], i});
        }
        return {-1,-1};
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {2, 7, 11, 15};
    vector<int> res;

    res = sol.TwoSum(v1, 13);    // expects  [0, 2], [2, 0]
    cout << " Naive Approach : " << res[0] << ", " << res[1] << endl;

    res = sol.TwoSum2(v1, 13);    // expects  [0, 2], [2, 0]
    cout << " Efficient Approach : " << res[0] << ", " << res[1] << endl;

    vector<int> v2 = {2, 2};
    res = sol.TwoSum(v2, 4);    // expects  [0, 1], [1, 0]
    cout << " Naive Approach : " << res[0] << ", " << res[1] << endl;

    res = sol.TwoSum2(v2, 4);    // expects  [0, 1], [1, 0]
    cout << " Efficient Approach : " << res[0] << ", " << res[1] << endl;

    vector<int> v3 = {};
        res = sol.TwoSum(v3, 9);    // expects {-1, -1}
    cout << " Naive Approach : " << res[0] << ", " << res[1] << endl;

    res = sol.TwoSum2(v3, 9);    // expects -1, -1
    cout << " Efficient Approach : " << res[0] << ", " << res[1] << endl;
    
    return 0;

}
