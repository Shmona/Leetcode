#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
class Solution {
public:
    // Naive solution
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        return nums[n-k];
    }
    // Using min heap
    int findKthLargest_pq(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int> > pq;

        for (auto x : nums)
        {
            pq.push(x);
            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
    // Using QuickSelect
    int findKthLargest_QS(vector<int>& nums, int k) {

        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
private:
    int partition (vector<int> & nums, int low, int high)
    {
        int pivot = nums[high];
        int i = low;

        for (int j = low; j < high; j++)
        {
            if(nums[j] <= pivot)
                swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[high]);
        return i;
    }
    int quickSelect(vector<int>& nums, int low, int high, int k)
    {
        if (low == high)
            return nums[low];
        
        int p = partition(nums, low, high);

        if (p == k)
            return nums[p];
        else if ( p < k)
            return quickSelect(nums, p + 1, high, k);
        else
            return quickSelect(nums, low, p - 1, k);
        
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {3,2,1,5,6,4};
    int k1 = 2;

    cout << sol.findKthLargest(v1, k1) << endl;  //expects 5
    cout << sol.findKthLargest_pq(v1, k1) << endl;
    cout << sol.findKthLargest_QS(v1, k1) << endl;

    vector<int> v2 = {3,2,3,1,2,4,5,5,6};
    int k2 = 4;
    cout << sol.findKthLargest(v2, k2) << endl;  //expects 4
    cout << sol.findKthLargest_pq(v2, k2) << endl; 
    cout << sol.findKthLargest_QS(v2, k2) << endl;

    return 0;
}
