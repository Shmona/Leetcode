#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
        //Naive Solution : TC = O(N^2) , SC = O(1)
        vector<int> countSmaller(vector<int>& nums) {
            int n = nums.size();
            vector<int> res (n,0);
            for (int i = 0; i < n; i++)
            {
                int count = 0;
                for (int j = i + 1; j < n; j++)
                {
                    if (nums[j] < nums[i])
                        count++;
                }
                res[i] = count;
            }
            return res;
        }

        //Using binary search: TC = O(N^2) , SC = O(N)
        vector<int> countSmaller_BS(vector<int>& nums) {
            int n = nums.size();
            vector<int> res (n,0);
            vector<int> sorted(n);

            int len = 0;

            for (int i = n - 1; i >= 0; i--)
            {
                int index = binarysearch(sorted, nums[i], 0, len - 1);
                res[i] = index;

                for (int k = len; k > index; --k) 
                    sorted[k] = sorted[k - 1];

                sorted[index] = nums[i];
                len++;   
            
            }
            return res;
        }

        //Using Merge sort counting : TC = O(N Log N) , SC = O(N)
        vector<int> countSmaller_MS(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n,0);

            vector<pair<int, int>> org(n), sorted(n);
            //store original index
            for (int i = 0 ; i < n; i++)
                org[i] = {nums[i], i};

            mergeSort(org, sorted, res, 0, n);
            return res;    
        }
    private:
        int binarysearch(vector<int>&sorted, int target, int low, int high)
        {
            int ans = high + 1;
            while (low <= high)
            {
                int mid = low + (high - low)/2;
                if (sorted[mid] >= target)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            return ans;
        }
        void mergeSort(vector<pair<int, int>> & org, vector<pair<int, int>> & sorted, vector<int> & res, int left, int right)
        {
            if (right - left <= 1) 
                return;
            
            int mid = left + (right - left)/2;
            mergeSort(org, sorted, res, left, mid);
            mergeSort(org, sorted, res, mid, right);

            int i = left, j = mid, k = left;
            while (i < mid && j < right)
            {
                if (org[i].first <= org[j].first)
                {
                    res[org[i].second] += (j - mid);
                    sorted[k++] = org[i++];
                }
                else
                    sorted[k++] = org[j++];
            }

            while (i < mid)
            {
                res[org[i].second] += (j - mid);
                sorted[k++] = org[i++];
            }

            while (j < right)
                sorted[k++] = org[j++];
            
            for ( int x = left; x < right; x++)
                org[x] = sorted[x];
        }
};

int main()
{
    Solution sol;
    vector<int> v1 = {5,2,6,1};

    vector<int> res = sol.countSmaller(v1);     //expects {2 1 1 0 }
    cout << "\n Results :  ";
    for (auto x : res)
        cout << x << " ";

    vector<int> res1 = sol.countSmaller_BS(v1);
    cout << "\n Results :  ";
    for (auto x : res1)
        cout << x << " ";

    vector<int> res2 = sol.countSmaller_MS(v1);
    cout << "\n Results :  ";
    for (auto x : res2)
        cout << x << " ";
    
    return 0;
}
