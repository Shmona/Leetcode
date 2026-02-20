#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        if ( n == 1)
            return heights[0];
        
        stack<int> st;
        int ans = 0;

        for( int right = 0; right <= n; right++)
        {
            int curr = (right == n)? 0 : heights[right];
            while (!st.empty() && heights[st.top()] > curr)
            {
                int mid = st.top();
                st.pop();

                int left =  st.empty() ? -1 : st.top();
                
                ans = max(ans, heights[mid]*(right - left - 1));
            }
            st.push(right);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {2,1,5,6,2,3};
    cout << sol.largestRectangleArea(v1) << endl;  // expects 10

    vector<int> v2 = {2,4};
    cout << sol.largestRectangleArea(v2) << endl;  // expects 4

    vector<int> v3 = {5,1,4};
    cout << sol.largestRectangleArea(v3) << endl;  // expects 5

    return 0;
}
