/*
You are given coordinates, a string that represents the coordinates of a square of the chessboard. 
Below is a chessboard for your reference.

Return true if the square is white, and false if the square is black.
The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first, 
and the number second.

Example 1:
    Input: coordinates = "a1"
    Output: false
    Explanation: From the chessboard above, the square with coordinates "a1" is black, so return false.

Example 2:
    Input: coordinates = "h3"
    Output: true
    Explanation: From the chessboard above, the square with coordinates "h3" is white, so return true.

Example 3:
    Input: coordinates = "c7"
    Output: false

###Constraints:
coordinates.length == 2
'a' <= coordinates[0] <= 'h'
'1' <= coordinates[1] <= '8'
*/

//USING MAP
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        map<char, int> m;
        m['a'] = 1, m['b'] = 2, m['c'] = 3, m['d'] = 4;
        m['e'] = 5, m['f'] = 6, m['g'] = 7, m['h'] = 8;

        int temp = m[coordinates[0]]+coordinates[1];

        return (temp&1);
    }
};

//Even - ODD logic
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        
        if (coordinates[0] == 'a'  ||coordinates[0] == 'c' || coordinates[0] == 'e'  || coordinates[0] == 'g')
            return ((coordinates[1] + 1)&1);
        else
            return (coordinates[1]&1);
    }
};

//Other way
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        
        if ((coordinates[0] + coordinates[1])&1)
            return true;
        else
            return false;
    }
};

//Optimal one : one line solution
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        
        return (coordinates[0] + coordinates[1])&1;
    }
};