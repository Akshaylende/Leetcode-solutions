/*
## 886. Possible Bipartition  ##


# Problem Link -
https://leetcode.com/problems/possible-bipartition/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.


# Query/ Code -
*/

// TC - O(NE)
// Sc - O(N)

class Solution {
public:
    bool BFS(unordered_map<int, vector<int>>& edges,int src, vector<int>& group){
        queue<int> que;
        que.push(src);
        group[src] = 0;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            int color = group[node] == 1 ? 0 : 1;
            for(auto x: edges[node]){
                if(group[x] == -1){
                    group[x] = color;
                    que.push(x);
                }
                else if(group[x] == group[node]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> edges;
        for(auto x: dislikes){
            edges[x[0]].push_back(x[1]);
            edges[x[1]].push_back(x[0]);
        }
        vector<int> group(n+1, -1);
        for(int i=1; i<=n; i++){
            if(group[i] == -1){
                if(!BFS(edges, i, group)) return false;
            }
        }
        return true;
    }
};