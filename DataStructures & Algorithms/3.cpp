/*
## 3. Longest Substring without Repeating Characters ##


# Problem Link - 
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given a string s, find the length of the longest substring without duplicate characters.

# Query/ Code - 
*/
// TC - O(N^2)
// SC - O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int result = 0, i=0;
        unordered_set<char> visit;
        for(int j=0; j<len; j++){
            if(visit.find(s[j]) != visit.end()){
                while(i<j && visit.find(s[j])!= visit.end()){
                    result=max(result, j-i);
                    visit.erase(s[i]);
                    i++;
                }
            }
            visit.insert(s[j]);
        }
        result = max(result, len-i);
        return result;
    }
};


// optimized version to reduce time complexity for this can we be pair of hashes with last position and then checking for if the last occurance is greater than i or not 
// based on this we can decide and move directly i to the last occurance which will remove the while list from the code
