/*
## 205. Isomorphic strings ##


# Problem Link - 
https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

# Query/ Code - 
*/
TC - O(N)
SC - O(N+N)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> mp1, mp2;
        for(int i=0;i<s.length();i++){
            if(mp1.find(s[i]) == mp1.end()) mp1[s[i]] = i;
            if(mp2.find(t[i]) == mp2.end()) mp2[t[i]] = i;
            if(mp1[s[i]] != mp2[t[i]]) return false;
        }
        return true;
    }
};