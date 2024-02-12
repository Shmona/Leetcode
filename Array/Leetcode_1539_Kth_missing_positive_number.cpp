/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

Example 1:
    Input: arr = [2,3,4,7,11], k = 5
    Output: 9
    Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
    Input: arr = [1,2,3,4], k = 2
    Output: 6
    Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 
##Constraints:
    1 <= arr.length <= 1000
    1 <= arr[i] <= 1000
    1 <= k <= 1000
    arr[i] < arr[j] for 1 <= i < j <= arr.length

Follow up: Could you solve this problem in less than O(n) complexity?
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();
        int ans = 0;
        if (arr[n-1] == n)
            ans = n+k;
        else if (arr[n-1] > n)
        {
            int missing_elements = arr[n-1] - n;
            //missing element is within array range
            if (k <= missing_elements)
            {
                int num = 1, count =0;
                int i = 0;
                while(i < n)
                {
                    if (arr[i] == num)
                        i++;
                    else 
                        count++;
                    
                    if (count == k)
                    {
                        ans = num;
                        break;
                    }
                    
                    num++;
                }
            }
            else
                ans = arr[n-1] + (k - missing_elements);
        }
        return ans;
    }
};

//optimal
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();
        if (arr[n-1] == n)
            return (n+k);
        
        int num = 0, count =0;
        int i = 0;
            
        while(i < n)
        {
            if (arr[i] == num +1)
            {
                i++;
                num++;
                continue;
            }
            num++;
            count++;
                    
            if (count == k)
                return  num;
        }
        return num+(k - count);
    }
};