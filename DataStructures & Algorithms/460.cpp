/*
## 460. LFU Cache ##


# Problem Link - 
https://leetcode.com/problems/lfu-cache/description/?envType=problem-list-v2&envId=ssd-ssd1-cache-system-design

# Problem Statement -
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 

# Query/ Code - 
*/

// TC - O(N logn)
// SC - O(N)

// Doubly Linkedlist Definition 
class listNode{
    public:
        int key, val;
        listNode *prev, *next;

        listNode(int key, int val){
            this->key = key;
            this->val = val;
            prev = next = NULL;
        }
};

// LRU Cache implementation for single list
class LRUCache{
    unordered_map<int, listNode *> queue;
    listNode *left, *right;
    public:
        LRUCache(){
            left = new listNode(-1, -1);
            right = new listNode(-1, -1);
            left->next = right;
            right->prev = left;
        }

        int getSize(){
            return queue.size();
        }

        listNode* getRef(int key){
            if(queue.find(key) == queue.end()) return NULL;
            return queue[key];
        }

        void put(int key, int val){
            if(queue.find(key) != queue.end()){
                removeNode(queue[key]);
            }
            listNode *node = new listNode(key, val);
            queue[key] = node;

            listNode *curr = right->prev;
            curr->next = node;
            node->next = right;
            node->prev = curr;
            right->prev = node;
        }

        void removeNode(listNode *node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            queue.erase(node->key);
        }

        listNode* removefirst(){
            if(getSize() == 0) return NULL;
            listNode *node = left->next;
            removeNode(node);
            return node;
        }
};


// LFU Cache Implementation
class LFUCache {
    int size;
    unordered_map<int, int> count;
    unordered_map<int, LRUCache *> cache;

    public:
        LFUCache(int capacity) {
            this->size = capacity;
        }
        
        int get(int key) {
            if(count.find(key) == count.end())
                return -1;
            LRUCache *list = cache[count[key]];
            listNode *node = list->getRef(key);
            list->removeNode(node);
            if(list->getSize() == 0){
                cache.erase(count[key]);
            }
            count[key]+=1;
            if(cache.find(count[key]) == cache.end()){
                list = new LRUCache();
                cache[count[key]] = list;
            }
            list = cache[count[key]];
            list->put(key, node->val);
            return node->val;
        }
        
        // put method
        void put(int key, int value) {
            LRUCache *list; 
            listNode *node;
            if(count.find(key) != count.end()){
                list = cache[count[key]];
                node = list->getRef(key);
                list->removeNode(node);
            }
            else check_valid();
            count[key] +=1;
            if(cache.find(count[key]) == cache.end()){
                list = new LRUCache();
                cache[count[key]] = list;
            }
            else list = cache[count[key]]; 
            list->put(key, value);
        }

        void check_valid(){
            if(count.size() == this->size){
                // cout<<"Max Capacity reached"<<endl;
                int minf = INT_MAX;
                for(auto[x, y] : count){
                    minf = min(y, minf);
                }
                // cout<<minf<<endl;
                LRUCache *list = cache[minf];
                listNode *node = list->removefirst();
                // cout<<node->key<<endl;
                if(node){
                    // cout<<node->key<< " size" <<endl;
                    count.erase(node->key);
                }
                else 
                    cout<<"Nothing Removed"<<endl;
                cout<< "After erase "<<node->key<<endl;
            }
        }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */