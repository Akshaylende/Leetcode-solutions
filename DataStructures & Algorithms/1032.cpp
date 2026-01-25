/*
## 1032. Stream of Characters ##


# Problem Link - 
https://leetcode.com/problems/stream-of-characters/description/?envType=problem-list-v2&envId=ssd-ssd2-data-stream-processing

# Problem Statement -
Design an algorithm that accepts a stream of characters and checks if a suffix of these characters is a string of a given array of strings words.

For example, if words = ["abc", "xyz"] and the stream added the four characters (one by one) 'a', 'x', 'y', and 'z', your algorithm should detect that the suffix "xyz" of the characters "axyz" matches "xyz" from words.

Implement the StreamChecker class:

StreamChecker(String[] words) Initializes the object with the strings array words.
boolean query(char letter) Accepts a new character from the stream and returns true if any non-empty suffix from the stream forms a word that is in words.

# Query/ Code - 
*/
// TC - O(N*L)
// SC - O(N)

class TrieNode{
    public:
        TrieNode* children[26] = {NULL};
        bool isLeaf;

        TrieNode(){
            isLeaf = false;
        }
};


class StreamChecker {
    TrieNode *root;
    string stream;
public:
    StreamChecker(vector<string>& words) {
       root = new TrieNode();
       this->stream = "";
       for(auto word : words){
        TrieNode *curr = root;
        for(int i = word.length()-1; i>=0; i--){
            if(!curr->children[word[i]-'a']){
                TrieNode *node = new TrieNode();
                curr->children[word[i]-'a'] = node;
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->isLeaf = true;
       }
    }
    
    bool query(char letter) {
        stream += letter;
        if(root->children[letter - 'a']){
            int len =stream.length()-1;
            return check_for_word(stream, root, len);
        }
        return false;
    }

    bool check_for_word(string &stream, TrieNode* curr, int ind){
        if(curr->isLeaf) return true;
        if(ind < 0 || !curr->children[stream[ind]-'a']) return false;
        return check_for_word(stream, curr->children[stream[ind]-'a'], ind-1);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */