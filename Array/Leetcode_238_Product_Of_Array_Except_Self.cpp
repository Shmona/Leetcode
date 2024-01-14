/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums
except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

### Constraints:
    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

/* Naive Approach
Space complexity = O(N) + O(N)
Time complexity = O(N)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> first(n, 1);  // store product from start
        vector<int> second(n, 1);  // store product from end

    for (int i = 1; i < n; ++i)
        first[i] = first[i - 1] * nums[i - 1];

    for (int i = n - 2; i >= 0; --i)
        second[i] = second[i + 1] * nums[i + 1];

    for (int i = 0; i < n; ++i)
      nums[i] = first[i] * second[i];

    return nums;
        
    }
};

/*Second approach
Space complexity = O(N)
Time complexity = O(N)
*/

# class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Use ans as the first product array.
        for (int i = 1; i < n; ++i)
            ans[i] = ans[i - 1] * nums[i - 1];

        int prod = 1;  // second product
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= prod;
            prod *= nums[i];
        }
        return ans;
    }
};