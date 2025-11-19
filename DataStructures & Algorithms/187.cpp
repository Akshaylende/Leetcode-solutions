/*
## 187 - Repeated DNA Sequences ##


# Problem Link - 
https://leetcode.com/problems/repeated-dna-sequences/?envType=problem-list-v2&envId=sliding-window

# Problem Statement -
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

# Query/ Code - 
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> repeated_DNA;
        unordered_map<string, int> mp;
        string pattern = "";
        int n = s.length();
        for(int i=0; i<n; i++){
            pattern+=s[i];
            if(i>9){
                pattern = pattern.erase(0,1);
            }
            if(i>8){
                mp[pattern] +=1;
                if(mp[pattern] == 2) repeated_DNA.push_back(pattern);
            }
        }
        return repeated_DNA;
    }
};