/*
## 841. Keys and Rooms ##


# Problem Link - 
https://leetcode.com/problems/keys-and-rooms/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

# Query/ Code - 
*/

// TC - O(N)
// SC - O(N)

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(0);
        visited[0] = true;
        while(!que.empty()){
            auto room = que.front();
            que.pop();
            for(auto x: rooms[room]){
                if(!visited[x]){
                    que.push(x);
                    visited[x] = true;
                }
            }
        }
        for(auto x: visited) if(!x) return false;
        return true;
    }
};