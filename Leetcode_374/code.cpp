#include <iostream>

using namespace std;


class Solution {
private:
    int picked;
    int guess(int num)
    {
        if (num == picked)
            return 0;
        else if (num < picked ) 
            return 1;
        return -1;
    }
public:
    Solution(int N)
    {
        picked = N;
    }

    int guessNumber(int n) {
        int low = 1, high = n;
        int mid = 0;

        while (low <= high)
        {
            mid = low + (high - low)/2;
            int pick = guess(mid);
            if (pick == 0)
                break;
            else if(pick == 1)
                low = mid + 1;
            else    
                high = mid - 1;
        }
        return mid;
    }
};

int main()
{
    Solution sol(13);
    cout << sol.guessNumber(20) << endl;

    return 0;
}
