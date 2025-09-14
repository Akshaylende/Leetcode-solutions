/*
## 68. Text Justification ##


# Problem Link - 
https://leetcode.com/problems/text-justification/description/

# Problem Statement -
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

# Query/ Code - 
TC - O(numRows * N)
SC - O(N)
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result; // storing the sentences
        vector<int> words_count; // storing word_count in a particular sentence
        int N = words.size(), cnt = 0;
        string sentence = "";
        // Iterating throught the words which is vector of strings
        for(int i=0; i<N; i++){
            int len = words[i].length();         // word length
            int currlen = sentence.length();     // sentence length at a particular Instance
            if(currlen + len > maxWidth){
                if(sentence[currlen-1] == ' ') sentence.pop_back();               // removing or popping the last space if present while pushing the sentence into result vector
                result.push_back(sentence);
                words_count.push_back(cnt);                // pushing the count of words in the present sentence
                // reseting values
                sentence = "";
                cnt = 0;
            }
            // adding words to the sentence & keeping the count of words in a particular sentence
            sentence += words[i];
            cnt++;
            // Checking for the space requirement
            if(i != N-1 && sentence.length() < maxWidth) sentence += " "; 
        }
        // checking for last word as we haven't checking while looping for last instance
        if(sentence.length()>0){
            result.push_back(sentence);
            words_count.push_back(cnt);
        }

        // Dealing with the spacing part 
        int size = result.size();
        for(int i=0; i<size; i++){
            cnt = words_count[i];
            sentence = result[i];
            // padding length requirement
            int extra = maxWidth - sentence.length();
            // single word or left aligned justification
            if(cnt<2 || i == size-1){
                while(sentence.length()< maxWidth) 
                sentence.push_back(' ');
            }
            else{
                // Here two cases will be there to handle spacing one which involve evenly distributed spaces among words or else leftly diverted spacing 
                int sp = extra/(cnt-1);
                int an = extra%(cnt-1);
                string temp(sp, ' ');
                sentence = "";
                for(int j=0;j< result[i].length();j++){
                    sentence +=result[i][j];
                    if(result[i][j] == ' '){
                        if(an>0) {
                            sentence+=' ';
                            an--;
                        }                            
                        sentence += temp;
                    }
                }
                
            }
            // Assigning padded sentence to result string 
            result[i] = sentence;
        }
        return result;
    }
};