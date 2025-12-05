/*
## 785. Is Graph Bipartite ##


# Problem Link - 
https://leetcode.com/problems/is-graph-bipartite/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

# Query/ Code - 
*/
// TC - O(N*N)
// SC - O(2N)

class Solution {
public:
    bool BFS(vector<vector<int>>& graph, int src, vector<int>& color){
        queue<pair<int, int>> que;
        que.push({src, 0});
        color[src] = 0;
        while(!que.empty()){
            auto [node, col] = que.front();
            que.pop();
            int next = col == 1? 0 : 1;
            for(auto x: graph[node]){
                if(color[x] == -1){
                    que.push({x, next});
                    color[x] = next;
                }
                else if(color[x] == col) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                bool bipartite = BFS(graph, i, color);
                if(!bipartite) return false;
            }
        }
        return true;
    }
};