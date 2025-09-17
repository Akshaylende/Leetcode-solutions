/*
##  383. Ransom Note ##


# Problem Link - 
https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

# Query/ Code - 
*/
//TC - O(N)
//SC - O(26)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alpha[26] = {0};
        for(auto lett:magazine){
            alpha[lett-97]++;
        }
        for(auto lett: ransomNote){
            if(alpha[lett-97]<1){
                return false;
            }
            alpha[lett-97]--;
        }
        return true;
    }
};