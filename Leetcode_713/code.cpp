#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    // Naive approach : TC = O(N^2) , SC = O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0 || k == 0)
            return 0;
        int count = 0;
        for (int i = 0 ; i < n; i++)
        {
            long long prod = 1;
            for ( int j = i; j < n; j++)
            {
                prod *= nums[j];
                if (prod < k) 
                    count++;
                else 
                    break;
            }
        }
        return count;
    }

    // Optimized approach : using sliding windows TC = O(N)
    int numSubarrayProductLessThanK_2(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0 || k == 0)
            return 0;
        
        long long prod = 1;
        int count = 0;
        int left = 0, right = 0;
        while (right < n)
        {
            prod *= nums[right];
            while (left <= right && prod >= k)
            {
                prod /= nums[left];
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
};

int main()
{
    vector<int> v = { 10, 5, 2, 6};
    int k = 100;
    Solution sol;
    cout << " No. of contiguous subarrays having prod less than " << k  << " = " 
         << sol.numSubarrayProductLessThanK(v, k) << endl;

    int k1 = 10;
    cout << " No. of contiguous subarrays having prod less than " << k1  << " = " 
         << sol.numSubarrayProductLessThanK(v, k1) << endl;


    cout << "using sliding windows :\n" ;
    cout << " No. of contiguous subarrays having prod less than " << k  << " = " 
         << sol.numSubarrayProductLessThanK_2(v, k) << endl;
        
    cout << " No. of contiguous subarrays having prod less than " << k1  << " = " 
         << sol.numSubarrayProductLessThanK_2(v, k1) << endl;

    return 0;
}
