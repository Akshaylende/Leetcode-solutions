/*
## 151. Reverse words in a string ##


# Problem Link - 
https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

# Query/ Code - 
/*
Time Complexity - O(N)
Space Complexity - O(N)

class Solution {
public:
    string reverseWords(string s) {
        int N = s.length();
        string word = "", result = "";
        stack<string> st;
        for(int i=0; i<N; i++){
            if(s[i] == ' '){
                if(word.length()>0){
                    st.push(word);
                    word = "";
                }
            }
            else word += s[i];
        }
        if(word.length()>0) st.push(word);
        while(!st.empty()){
            word = st.top();
            st.pop();
            result += word;
            if(!st.empty()) result += " ";
        }
        return result;
    }
};

int main(){
    cout<< reverseWords("the sky is blue")<<endl;
    return 0;
}
*/
