/*
## 150. Evaluate Reverse Polish Notation ##


# Problem Link - 
https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -


# Query/ Code - 
*/

// TC - O(N)
// SC - O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int N = tokens.size();
        stack <int> st;
        for(int i=0; i<N; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if(tokens[i] == "+") st.push(first + second);
                if(tokens[i] == "-") st.push(second - first);
                if(tokens[i] == "*") st.push(first * second);
                if(tokens[i] == "/") st.push(second / first);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.empty() ? -1 : st.top();
    }
};