/*
## 432. All O' one Data Structure ##


# Problem Link - 
https://leetcode.com/problems/all-oone-data-structure/?envType=problem-list-v2&envId=ssd-ssd3-data-structure-design

# Problem Statement -
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.

# Query/ Code - 
*/
// TC - O(1)
// SC - O(N)

class Node{
    public:
    int freq;
    Node *prev, *next;
    unordered_set<string> keys;

    Node(int val){
        this->freq = val;
        prev = next = NULL;
    }
};


class AllOne {
    unordered_map<string, Node* >map;
    Node *left, *right;
public:
    AllOne() {
        left = new Node(0);
        right = new Node(0);
        left->next = right;
        right->prev = left;
    }
    
    void inc(string key) {
        if(map.find(key) != map.end()){
            Node *node = map[key];
            int freq = node->freq;
            node->keys.erase(key);
            Node *nextNode = node->next;
            if(nextNode == right || nextNode->freq != freq+1){
                Node *newNode = new Node(freq+1);
                newNode->keys.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
                nextNode->prev = newNode;
                node->next = newNode;
                map[key] = newNode;
            } 
            else{
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }
            if(node->keys.size()==0){
                removeNode(node);
            }
        }
        else{
            Node *node = left->next;
            int freq = node->freq;
            if(node == right || freq > 1){
                Node *newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->prev = left;
                newNode->next = node;
                node->prev = newNode;
                left->next = newNode;
                map[key] = newNode;
            }
            else{
                node->keys.insert(key);
                map[key] = node;
            }
        }
    }
    
    void dec(string key) {
        Node *node = map[key];
        int freq = node->freq;
        node->keys.erase(key);
        if(freq == 1)
            map.erase(key);
        else{
            Node *prevNode = node->prev;
            if(node == left || prevNode->freq < freq-1){
                Node *newNode = new Node(freq-1);
                newNode->keys.insert(key);
                newNode->prev = prevNode;
                newNode->next = node;
                node->prev = newNode;
                prevNode->next = newNode;
                map[key] = newNode;
            }
            else{
                prevNode->keys.insert(key);
                map[key] = prevNode;
            }
        }
        if(node->keys.size() == 0)
            removeNode(node);
        
    }
    
    string getMaxKey() {
        Node *node = right->prev;
        if(node == left) return "";
        return *(node->keys.begin());
    }
    
    string getMinKey() {
        Node *node = left->next;
        if(node == right) return "";
        return *(node->keys.begin());
    }
    void removeNode(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */