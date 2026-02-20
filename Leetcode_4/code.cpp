#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    //using Two-pointer approach TC = O(m + n), SC = O(m + n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int  l = m+n;

        int k = 0, i = 0, j = 0;
        vector<int> merge (l, 0);

        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
                merge[k++] = nums1[i++];      
            else
                merge[k++] = nums2[j++];
        }
        while (i < m)
            merge[k++] = nums1[i++];

        while (j < n)
            merge[k++] = nums2[j++];
    
        if (l%2 == 0)
            return (double)(merge[l/2] + merge[l/2 - 1])/2;
        else
            return (double)merge[l/2];
    }

    //using Binary Search approach TC = O(log(min(m,n))), SC = O(1)
    double findMedianSortedArrays_BS(vector<int>& nums1, vector<int>& nums2) {
        // ensure first array is smaller in size
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays_BS(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int total = m+n;
        int half = (total + 1)/2;

        int l1 = 0 , h1 = m;

        while (l1 <= h1)
        {
            int i = l1 + ( h1 - l1 )/2;
            int j = half - i;

            int Aleft = (i == 0 ) ? INT_MIN : nums1[i-1];
            int Aright = (i == m ) ? INT_MAX : nums1[i];

            int Bleft = (j == 0 ) ? INT_MIN : nums2[j-1];
            int Bright = (j == n ) ? INT_MAX : nums2[j];

            //check partition condition 2 : All left elements ≤ all right elements
            if (Aleft <= Bright  && Bleft <= Aright)
            {
                if (total%2 == 1)
                    return (double)max(Aleft, Bleft);
                else
                return (double)(max(Aleft, Bleft) + min(Aright, Bright))/2;
            }
            else if (Aleft > Bright)
                h1 = i - 1;
            else
                l1 = i + 1;
        }
        return 0.0;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1,3};
    vector<int> v2 = {2};
    cout << sol.findMedianSortedArrays(v1, v2) << endl;    // expects  2.00000
    cout << sol.findMedianSortedArrays_BS(v1, v2) << endl;

    vector<int> v3 = {1,2};
    vector<int> v4 = {3,4};
    cout << sol.findMedianSortedArrays(v3, v4) << endl;    // expects   2.50000
    cout << sol.findMedianSortedArrays_BS(v3, v4) << endl;   
    return 0;
}
