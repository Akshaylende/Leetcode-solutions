/*
## 58. Length of Last Word ##


# Problem Link - 
https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(1)


class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int N = s.length();
        for(int i = N-1; i>=0; i--){
            if(s[i] == ' '){
                if(length != 0) break; 
            }
            else{
                length++;
            }
        }
        return length;
    }
};

int main(){
    cout<< lengthOfLastWord(" fly me to the moon ") <<endl;
    return 0;
}