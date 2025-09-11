/*
## 392. Is Subsequence ##


# Problem Link - 
https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

# Query/ Code - 
*/

/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == t) return true;
        int N = t.length();
        int i = 0;
        for(int j=0; j<N; j++){
            if(t[j] == s[i]) i++;
            if(i == s.length()) return true;
        }
        return false;
    }
};
int main(){
    cout<<isSubsequence("abc", "ahbgdc")<<endl;
    return 0;
}
*/