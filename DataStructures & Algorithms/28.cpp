/*
## 28. Find the index of the First Occurence in the string ##


# Problem Link - 
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

# Query/ Code - 
*/
/*
Time Complexity - O(N)
Space Complexity - O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        string word = "";
        int n = needle.length();
        for(int i=0;i<haystack.length();i++){
            if(haystack[i] == needle[0]){
                word = haystack.substr(i, n);
                if(word == needle) return i;
            }
        }
        return -1;
    }
};

int main(){
    cout<<strstr("sadbutsad", "sad")<<endl;
    return 0;
}
*/