# Problem Statement : Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

**Example 1:**

    Input: piles = [3,6,7,11], h = 8
    Output: 4

**Example 2:**

    Input: piles = [30,11,23,4,20], h = 5
    Output: 30

**Example 3:**

    Input: piles = [30,11,23,4,20], h = 6
    Output: 23
 
## Constraints:
- 1 <= piles.length <= 10^4
- piles.length <= h <= 10^9
- 1 <= piles[i] <= 10^9

## Approach 

**IDEA**    

    - Guess the eating speed and check if it works.
    - If Koko eats at speed k bananas/hour:

            Time to finish a pile of size p  =  ceil(p / k) hours
            Total time  =  sum of ceil(p_i / k) for all piles

    - As eating speed k increases, the total hours needed never increases. So the function hours_needed(k) is monotonically decreasing.


### Using Binary Search (Minimum k such that hours_needed(k) ≤ h ) :  TC = O(N), SC = O(1)
- Solution Link : https://leetcode.com/problems/koko-eating-bananas/submissions/1932878146/

- Apply binary search for a range [low, high] 
        
        => low =  1 (as Koko eats at least 1 banana per hour) 
        => high =  max_element present in the given piles  (If Koko eats the largest pile in one hour, she can finish all piles)

- While low <= high :
        
        :  compute mid and treat it as eating speed (k)
        :  if hours_needed(mid)  <= h  : store mid as ans and look further left to get minimum value of k
        :  if hours_needed(mid)  > h   : discard that left half and move to right half
- return ans
