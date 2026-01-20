/*
## 381. Insert Delete GetRandom - O(1) Duplicates allowed ##


# Problem Link - 
https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

# Problem Statement -
RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). It should support inserting and removing specific elements and also reporting a random element.

Implement the RandomizedCollection class:

RandomizedCollection() Initializes the empty RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the item is not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements. The probability of each element being returned is linearly related to the number of the same values the multiset contains.
You must implement the functions of the class such that each function works on average O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least one item in the RandomizedCollection.

# Query/ Code - 
*/
// TC - O(1)
// SC - O(N)

class RandomizedCollection {
    vector<pair<int, int>> list;
    unordered_map<int, vector<int>> map;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        map[val].push_back(list.size());
        list.push_back({val, map[val].size()-1});
        return map[val].size() == 1;
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end()) return false;
        auto last = list.back();
        map[last.first][last.second] = map[val].back();
        list[map[val].back()] = last;
        map[val].pop_back();
        if(map[val].size() == 0)
            map.erase(val);
        list.pop_back();
        return true;
    }
    
    int getRandom() {
        int idx = rand() % list.size();
        return list[idx].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */