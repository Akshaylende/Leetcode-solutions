/*
## 224. Basic Calculator ##


# Problem Link - 
https://leetcode.com/problems/basic-calculator/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

# Query/ Code - 
*/

// TC - O(N)
// SC - O(1)

class Solution {
public:
    pair<int, int> resolve_brackets(string &exp, int start, int length){
        int val = 0, sig = 1;
        string num = "";
        for(int i = start+1; i<length; i++){
            if(isdigit(exp[i])){
                if(i+1 < length && isdigit(exp[i+1])){
                    num += exp[i];
                    continue;
                }
                num += exp[i];
                val +=  (sig * stoi(num));
                num = "";
                sig = 1;
            }
            else if(exp[i] == '-') sig = -1;
            else if(exp[i] == '('){
                auto [value, id] = resolve_brackets(exp, i, length);
                val += (sig * value);
                sig = 1;
                i = id;
                // cout<< "index "<< i << " val "<< val<< endl;

            }
            else if(exp[i] == ')') {
                start = i;
                break;
            }
        }
        return {val, start};
    }
    int calculate(string s) {
        int res = 0, sign = 1;
        int len = s.length();
        string nums = "";
        for(int i=0; i<len; i++){
            if(isdigit(s[i])){
                if(i+1 < len && isdigit(s[i+1])){
                    nums += s[i];
                    continue;
                }
                nums += s[i];
                res +=  (sign * stoi(nums));
                nums = "";
                sign = 1;
            }
            else if(s[i] == '-') sign = -1;
            else if(s[i] == '('){
                auto [val, idx] = resolve_brackets(s, i, len);
                res += (sign * val);
                sign = 1;
                i = idx;
            }
            // cout<< "index "<< i << " res "<< res<< endl;
        }
        return res;
    }
};