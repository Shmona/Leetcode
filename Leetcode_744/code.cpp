#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    //Naive solution
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto x : letters) 
        {
            if (x > target)
                return x;
        }
        return letters[0];
    }
    // Binary search 
    char nextGreatestLetter_BS(vector<char>& letters, char target) {
        int n = letters.size();

        int low = 0, high = n-1;
        while (low <= high)
        {
            int mid = low + (high - low)/2;
            if (letters[mid] <= target)
                low = mid + 1;   
            else
               high = mid - 1; 
        }
        return letters[low%n];
    }
};

int main()
{
    Solution sol;
    vector<char> v1 = {'c','f','j'};
    char t1 = 'a';

    cout << sol.nextGreatestLetter(v1,t1) << endl;       // expects "c"
    cout << sol.nextGreatestLetter_BS(v1,t1) << endl;   

    char t2 = 'c';

    cout << sol.nextGreatestLetter(v1,t2) << endl;       // expects "f"
    cout << sol.nextGreatestLetter_BS(v1,t2) << endl;  
     
    vector<char>  v3 = {'x','x','y','y'};
    char t3 = 'z';

    cout << sol.nextGreatestLetter(v3,t3) << endl;       // expects "x"
    cout << sol.nextGreatestLetter_BS(v3,t3) << endl; 

    return 0;
}
