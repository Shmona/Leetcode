#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    // using quick sort 
    vector<int> sortArray(vector<int>& nums) {

        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
    // using priority queue
    vector<int> sortArray_pq(vector<int>& nums) {

        priority_queue<int> pq;
        for (auto x : nums)
            pq.push(x);

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            nums[i] = pq.top();
            pq.pop();
        }
        return nums;
        
    }
private:
    void quicksort(vector<int>&nums, int low, int high)
    {
        if (low >= high)
            return;
        int p = partition(nums, low , high);

        quicksort(nums, low, p-1);
        quicksort(nums, p+1, high);
        
    }
    //Lomuto partition
    int  partition(vector<int> & nums, int low, int high)
    {
       int pivot = nums[high];
       int i = low;

       for ( int j = low ; j < high; j++)
       {
            if (nums[j] <= pivot)
                swap(nums[i++], nums[j]);
       }
       swap(nums[i], nums[high]);
       return i;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {5,2,3,1};
    sol.sortArray(v);
    cout << "\n Sorted array : ";
    for (auto x : v)
        cout << x << "  ";

    vector<int> v1 = {5,2,3,1};
    sol.sortArray_pq(v1);
    cout << "\n Sorted array : ";
    for (auto x : v1)
        cout << x << "  ";
    
    return 0;
}
