/*
## 6. zigzag Conversion ##


# Problem Link - 
https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

# Query/ Code - 
TC - O(N)
SC - o(N)
*/

class Solution {
public:
    string convert(string s, int numRows) {
        int N = s.length();
        if(numRows == 1) return s;
        vector<bool> visit(N, false);
        string res = "";
        for(int i=0; i<numRows; i++){
            bool flag = false;
            int j = i;
            while(j<N){
                flag = !flag;
                if(!visit[j]) res += s[j];
                visit[j] = true;
                if(flag){
                    j += 2*((numRows-1)-i);
                }
                else{
                    j+= 2*i;
                }
            }
        }
        return res;
    }
};


// Optimized approach will be to remove visit array which consist of the edge cases of numRows = 0 and numRows ending;
// Here things are repeating and for that just tweak the flag condition for j for only considering one part instead of two
 