/*
## 1042. Flower planting with no Adjacent ##


# Problem Link - 
https://leetcode.com/problems/flower-planting-with-no-adjacent/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

# Query/ Code - 
*/

// TC - O(O+E)
// SC - O(N+E)

class Solution {
public:
    void BFS(unordered_map<int, vector<int>>& edges, int src, vector<int>& flower){
        queue<pair<int, int>> que;
        que.push({src, 0});
        while(!que.empty()){
            auto [node, type] = que.front();
            que.pop();
            vector<bool> used(4, false);
            for(auto x:edges[node]){
                if(flower[x] != -1)
                    used[flower[x]]= true;
            }
            while(used[type]){
                type = (type+1)%4;
            } 
            flower[node] = type;
            used[type] =true;
            for(auto x: edges[node]){
                if(flower[x] == - 1|| flower[x] == flower[node]){
                    while(used[type]){
                        type = (type+1) % 4;
                    }
                    que.push({x, type});
                    used[type] = true;
                }
            }

        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> edges;
        for(auto x: paths){
            edges[x[0]-1].push_back(x[1]-1);
            edges[x[1]-1].push_back(x[0]-1);
        }
        vector<int> flower(n, -1);
        for(int i = 0; i < n; i++){
            if(flower[i]==-1){
                BFS(edges, i, flower);
            }
        }
        for(int i =0; i<n;i++) flower[i]++;
        return flower;
    }
};