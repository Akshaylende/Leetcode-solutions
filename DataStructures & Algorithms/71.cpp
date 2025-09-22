/*
## 71. Simplify Path##


# Problem Link - 
https://leetcode.com/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

# Query/ Code - 
*/

// TC - O(N) 
// SC - O(N)

class Solution {
public:
    string simplifyPath(string path) {
        stack <string> st, st2;
        string res = "", temp="";
        int N = path.length();
        for(int i=0; i<N; i++){
            if(path[i] == '/'){
                if(temp.length()>0) {
                    if(temp == ".."){
                        if(st.size()>1){
                            st.pop();
                            st.pop();
                        }
                    }
                    else if(temp == "."){
                        if(st.size()>1) st.pop();
                    }
                    else {
                        st.push(temp);
                    }
                    
                }
                if(st.empty() || st.top() != "/") st.push("/");
                temp = "";
            }
            else{
                temp += path[i];
            }
        }
        if(temp.length()>0) {
                    if(temp == ".."){
                        if(st.size()>1){
                            st.pop();
                            st.pop();
                        }
                    }
                    else if(temp == "."){
                        if(st.size()>1) st.pop();
                    }
                    else {
                        st.push(temp);
                    }
                    
                }
        if(st.size()>1 && st.top() == "/") st.pop();
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty()){
            res+=st2.top();
            st2.pop();
        }
        return res.length() == 1 ? res: res.substr(0, res.length());
    }
};