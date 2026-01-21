#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Approach 1 : Two Pointer 
    int maxArea(vector<int>&height) 
    {
        int left = 0;
        int right = height.size() - 1;

        int Area = 0;
        while (right > left)
        {
            int temp = min(height[right], height[left]) *(right - left);
            Area = max(temp, Area);

            if (height[left] < height[right])
                left++;
            else
                right--;

        }
        return Area; 
    }

    // Approach 2 : Greedy algo 
    int maxArea2(vector<int>&height) {
        int left = 0;
        int right = height.size() - 1;

        int Area = 0;
        while (right > left)
        {
            int temp ;
            if(height[right] > height[left])
            {
                temp = height[left] *(right - left);
                left++;
            }
            else if (height[right] < height[left])
            {
                temp = height[right] *(right - left);
                right--;
            }
            else
            {
                temp = height[right] *(right - left);
                right--;
                left++;
            }
            Area = max(temp, Area);
        }
        return Area; 
    }
};

int main()
{
    Solution sol;
    vector<int> v ={1,8,6,2,5,4,8,3,7};   //expect 49
    cout << "Approach 1 :  Two Pointer :   "<< sol.maxArea(v) << endl;
    cout << "Approach 2 :  Greedy algo  : "<< sol.maxArea2(v) << endl;

    
    vector<int> a = {1, 1};                  // expect 1
    cout << "Approach 1 :  Two Pointer :   "<< sol.maxArea(a) << endl;
    cout <<"Approach 2 :  Greedy algo  : "<< sol.maxArea2(a) << endl;

    vector<int> b = {4, 3, 2, 1, 4};         // expect 16
    cout <<"Approach 1 :  Two Pointer :   "<< sol.maxArea(b) << endl;
    cout <<"Approach 2 :  Greedy algo  : "<< sol.maxArea2(b) << endl;

    vector<int> c = {1, 2, 1};               // expect 2
    cout << "Approach 1 :  Two Pointer :   "<<sol.maxArea(c) << endl;
    cout <<"Approach 2 :  Greedy algo  : "<< sol.maxArea2(c) << endl;

    vector<int> d = {};                      // expect 0
    cout <<"Approach 1 :  Two Pointer :   "<< sol.maxArea(d) << endl;
    cout <<"Approach 2 :  Greedy algo  : "<< sol.maxArea2(d) << endl;

    vector<int> e = {5};                     // expect 0
    cout <<"Approach 1 :  Two Pointer :   "<< sol.maxArea(e) << endl;
    cout <<"Approach 2 :  Greedy algo  : "<< sol.maxArea2(e) << endl;

    return 0;
}
