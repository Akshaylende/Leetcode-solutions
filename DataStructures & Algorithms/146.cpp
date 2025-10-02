/*
## 146. LRU Cache ##


# Problem Link - 
https://leetcode.com/problems/lru-cache/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)

class LRUCache {
    // Definition for Doubly Linkedlist
    class ListNode{
        public:
            int key, val;
            ListNode *prev, *next;
            ListNode(int key, int val){
                this->key = key;
                this->val = val;
                prev = next = NULL;
            }
    };
public:
    int size;
    ListNode *left, *right;
    unordered_map <int, ListNode *> mp;
    LRUCache(int capacity) {
        this -> size = capacity;
        this -> left = new ListNode(-1, -1);
        this -> right = new ListNode(-1, -1);
        left -> next = right;
        right -> prev = left;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        auto node = mp[key];
        removeListNode(node);
        updateListNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
            removeListNode(mp[key]);
        mp[key] = new ListNode(key, value);
        updateListNode(mp[key]);
        if(mp.size() > this -> size) {
            mp.erase(left->next->key);
            removeListNode(left->next); 
        }
    }

    // removing node from our queue
    void removeListNode(ListNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    } 

    // adding to the most Recently used node
    void updateListNode(ListNode *node){
        ListNode *curr = right -> prev;
        curr -> next = node;
        node-> prev = curr;
        node -> next = right;
        right -> prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */