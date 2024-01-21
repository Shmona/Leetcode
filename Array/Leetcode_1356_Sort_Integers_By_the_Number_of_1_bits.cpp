/*
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's
in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

Example 1:
    Input: arr = [0,1,2,3,4,5,6,7,8]
    Output: [0,1,2,4,8,3,5,6,7]
    Explantion: [0] is the only integer with 0 bits.
    [1,2,4,8] all have 1 bit.
    [3,5,6] have 2 bits.
    [7] has 3 bits.
    The sorted array by bits is [0,1,2,4,8,3,5,6,7]

Example 2:
    Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
    Output: [1,2,4,8,16,32,64,128,256,512,1024]
    Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
 
###Constraints:
    1 <= arr.length <= 500
    0 <= arr[i] <= 10^4
*/

/*
Naive Approach
Time complexity : O(N^2)
Space complexity : O(N)
*/

class Solution {
public:
    // to calculate no. of 1's 
    int count_ones( int n)
    {
        int ans = 0;
        while (n)
        {
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        int N = arr.size();
        vector<int> count(N,0);

        for (int i = 0; i < N; i++)
            count[i] = count_ones(arr[i]);


        for(int i = 0; i < N - 1; i++)    
        {  
            for(int j = i + 1; j < N; j++) 
            {
                if( count[i] > count[j])
                {
                    swap(arr[i], arr[j]);
                    swap(count[i], count[j]);          
                }
                else if(count[i] == count[j])
                {
                    if(arr[i] > arr[j])
                        swap(arr[i], arr[j]);
                }
            } 
        }
        return arr;

    }
};

/*
Better Approach
Time complexity : O(N^2)
Space complexity : O(1)
*/

class Solution {
public:
    // to calculate no. of 1's 
    int count_ones( int n)
    {
        int ans = 0;
        while (n)
        {
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        int N = arr.size();
        for(int i = 0; i < N - 1; i++)    
        {  
            for(int j = i + 1; j < N; j++) 
            {
                if( count_ones(arr[i]) > count_ones(arr[j]))
                    swap(arr[i], arr[j]);         
                else if(count_ones(arr[i]) == count_ones(arr[j]))
                {
                    if(arr[i] > arr[j])
                        swap(arr[i], arr[j]);
                }
            } 
        }
        return arr;

    }
};

/*
Best Approach
Time complexity : O(N)
Space complexity : O(1)
*/

class Solution {
public:
    // to calculate no. of 1's 
    int count_ones( int n)
    {
        int ans = 0;
        while (n)
        {
            n = n & (n-1);
            ans++;
        }
        return ans;
    }

    // to compare the no. of 1's
    static bool compare_ones(pair<int,int> &p1, pair<int,int> &p2)
    {
        if (p1.second < p2.second)
            return true;
        else if (p1.second == p2.second)
        {
            if(p1.first < p2.first)
                return true;
            else
                return false;
        }
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> res;
        int N = arr.size();

        for (int i = 0; i < N; i++)
            res.push_back({arr[i], count_ones(arr[i])});
        
        sort(res.begin(), res.end(), compare_ones);

        int i = 0;
        for (auto x : res)
        {
            arr[i] = x.first;
            i++;
        }
        return arr;
    }
};


