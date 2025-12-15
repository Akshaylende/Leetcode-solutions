/*
## 310. Minimum Height Trees ##


# Problem Link - 
https://leetcode.com/problems/minimum-height-trees/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

# Query/ Code - 
*/
// TC - O(N+E)
// SC - O(N)

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0), res;
        unordered_map<int, vector<int>> mp;
        for(auto x: edges){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
            indegree[x[0]]++;
            indegree[x[1]]++;
        }
        queue<pair<int, int>>que;
        for(int i=0; i<n; i++){
            if(indegree[i] == 1) que.push({1, i});
        }
        int minh = 0;
        while(!que.empty()){
            auto [height, node] =  que.front();
            que.pop();
            if(minh < height){
                res.clear();
                minh = height;
            }
            res.push_back(node);
            for(auto x: mp[node]){
                indegree[x]--;
                if(indegree[x]==1) que.push({height+1, x});
            }
        }
        if(edges.size() == 0) return {0};
        return res;
    }
};