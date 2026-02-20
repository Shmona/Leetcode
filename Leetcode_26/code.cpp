#include <iostream> 
#include <vector>

using namespace std;

class Solution
{
    public:
        // Using slow-fast pointer  with modified array without duplicates
        int removeDuplicates(vector<int> &v)
        {
            int n = v.size();
            if ( n == 0 )
                return 0;
            int k = 0;
            for(int i = 0; i < n-1; i++)
            {
                if( v[i] != v[i+1])
                    v[k++] = v[i];
            }
            v[k++] = v[n-1];
            v.resize(k);
            return v.size();
        }
        // Using slow-fast pointer
        int removeDuplicates_2(vector<int>& nums) {

            int n = nums.size();
            if (n == 0)
                return 0;
            
            int slow = 0;
            for ( int fast = 1; fast < n; fast++)
            {
                if (nums[slow] != nums[fast])
                {
                    slow++;
                    nums[slow] = nums[fast];
                }
            }
            return (slow+1); 
        }
};

int main()
{
    Solution sol;

    // Approach 1 
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    cout << " Approach 1  : " << sol.removeDuplicates(v) << endl;   // expects {0  1  2  3  4 }
    for (auto x : v)
        cout << x << "  ";

    cout << endl;
    vector<int> v1 = {1,1,2};
    cout << " Approach 1  : " << sol.removeDuplicates(v1) << endl;  // expects {1  2}
    for (auto x : v1)
        cout << x << "  ";

    
    cout << endl;
    // Approach 2
    vector<int> v3 = {0,0,1,1,1,2,2,3,3,4};
    cout << " Approach 2  : " << sol.removeDuplicates_2(v3) << endl;
    for (auto x : v3)
        cout << x << "  ";

    cout << endl;
    vector<int> v4 = {1,1,2};
    cout << " Approach 2  : " << sol.removeDuplicates_2(v4) << endl;
    for (auto x : v4)
        cout << x << "  ";

    return 0;
}
