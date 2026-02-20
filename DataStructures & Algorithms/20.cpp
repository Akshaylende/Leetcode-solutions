/*
## 20. Valid Parentheses ##


# Problem Link - 
https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int len = s.length();
        for(int i=0; i<len; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(s[i] == ')' && st.top()=='(') st.pop();
                else if(s[i] == ']' && st.top()=='[') st.pop();
                else if(s[i] == '}' && st.top()=='{') st.pop();
                else return false;
            }
        }
        return st.empty() ? true : false;
    }
};

// Approach -
1. Initialize a stack and Iterate through a loop.
2. Check if the paranthesis is opening one if it is then add it to stack 
3. else check for for possible first opposite parenthesis and return false if stack is empty or doesnot match with the parenthesis.
