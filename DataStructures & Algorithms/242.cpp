/*
## 242. Valid Anagram ##


# Problem Link - 
https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

# Query/ Code - 
*/
// TC - O(N)
// sc = O(26)

class Solution {
public:
    bool isAnagram(string s, string t) {
        int alpha[26] = {0};
        int len = s.length();
        if(len != t.length()) return false;
        for(int i=0; i<len; i++){
            alpha[s[i]-97]++;
            alpha[t[i]-97]--;
        }
        for(int i=0;i<26;i++){
            if(alpha[i] != 0) return false;
        }
        return true;
    }
};