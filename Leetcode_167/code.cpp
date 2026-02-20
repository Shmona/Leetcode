#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();
        int left = 0, right = n-1;

        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)
                return {left+1, right+1};
            else if (numbers[left] + numbers[right] < target)
                left++;
            else
                right--;
        }
        return {-1,-1};
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {2,7,11,15};
    int t1 = 9;

    vector<int> res1 = sol.twoSum(v1, t1);
    cout << " Element having sum equal to " << t1 << " : \n";
    for (auto x : res1)
    {
        if ( x != -1)
            cout << "index " << x -1 << " element  " << v1[x-1] << endl;
        else 
        {   
            cout << " Combination does not exists";
            break;
        }
    }
    vector<int> v2 = {-1,0};
    int  t2 = -1;
    vector<int> res2 = sol.twoSum(v2, t2);
    cout << " \n Element having sum equal to " << t2 << " : \n";
    for (auto x : res1)
    {
        if ( x != -1)
            cout << "index " << x -1 << " element  " << v2[x-1] << endl;
        else 
        {  
            cout << " Combination does not exists";
            break;
        }
    }

    vector<int> v3 = {-1,0, 7, 8, 10};
    int  t3 = 16;
    vector<int> res3 = sol.twoSum(v3, t3);
    cout << " \n Element having sum equal to " << t3 << " : \n";
    for (auto x : res3)
    {
        if ( x != -1)
            cout << "index " << x -1 << " element  " << v3[x-1] << endl;
        else
        {   
            cout << " Combination does not exists";
            break;
        }
    }

    return 0;
}
