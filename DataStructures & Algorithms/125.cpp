/*
## 125. Valid Palindrome ##

# Problem Link - 
https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

# Query/ Code - 
*/

/*
TC - O(N)
SC - O(1)

class Solution {
public:
    bool ispalin(string str){
        int N = str.length();
        int i = 0, j = N-1;
        while(i<j){
            if(str[i] != str[j]) return false;
            i++, j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str = "";
        int N = s.length();
        for(int i=0; i<N; i++){
            if(isalnum(s[i])){
                str += tolower(s[i]);
            }
        }
        return ispalin(str);
    }
};
*/