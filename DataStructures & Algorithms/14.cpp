/*
## 14. Longest common Prefix ##


# Problem Link - 
https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

# Query/ Code - 
*/
// TC - O(N*N)
// SC - O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();
        if(N==0) return "";
        string res = strs[0];
        for(int i=1; i<N; i++){
            auto str1 = strs[i];
            int j = 0; 
            for(j=0; j<min(res.size(), str1.size());j++){
                if(res[j]!= str1[j]) break;
            }
            res = res.substr(0, j);
        }
        return res;
    }
};

int main(){
    cout<<longestCommonPrefix(["flower","flow","flight"])<<endl; //fl
    return 0;
}