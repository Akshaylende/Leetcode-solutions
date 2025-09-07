/*
## 380. Insert Delete GetRandom O(1) ##

# Problem Link - 
https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity

# Query/ Code - 
*/
// TC - O(1)
// SC - O(2N)

class RandomizedSet {
public:
    vector<int> order;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            int N = order.size();
            order.push_back(val);
            mp[val] = N;
            return true;
        }    
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            nums[mp[val]] = nums.back();
            num.erase(nums.back());
            mp.erase(val);
            return true;
        }
        return false;   
    }
    
    int getRandom() {
        int N = nums.size();
        int index = rand() % N;
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

 int main(){
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(val);
    bool param_2 = obj->remove(val);
    int param_3 = obj->getRandom();
    
    cout<< param_1 << " "<< param_2 << " " << param_3 << endl;
    return 0;
 }