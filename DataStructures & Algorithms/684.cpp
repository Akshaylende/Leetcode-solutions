/*
## 684. Redundant Connection ##


# Problem Link - 
https://leetcode.com/problems/redundant-connection/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)

class DisjointSet{
    private:
        vector<int> rank, parent;
    public:
        DisjointSet(int size){
            rank.resize(size+1, 0);
            for(int i=0;i<=size;i++){
                parent.push_back(i);
            }
        }
        int find_ult_parent(int node){
            if(parent[node] == node){
                return node;
            }
            return parent[node] = find_ult_parent(parent[node]);
        }
        pair<int, int> union_by_rank(int u, int v){
            int parent_u = find_ult_parent(u);
            int parent_v = find_ult_parent(v);
            if(parent_u == parent_v) return {u,v};
            if(rank[parent_u] < rank[parent_v]){
                parent[parent_u] = parent_v;
            }
            else{
                if(rank[parent_u]== rank[parent_v]) rank[parent_u]++;
                parent[parent_v] = parent_u;
            }
            return {-1, -1};
        }
        
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n  = 0;
        for(auto edge : edges){
            n = max(n, edge[0]);
            n =  max(n, edge[1]);
        }
        DisjointSet obj = DisjointSet(n);
        pair<int, int> res;
        for(auto edge : edges){
            auto [x, y] = obj.union_by_rank(edge[0], edge[1]);
            if(x != -1){
                res.first = x;
                res.second = y;
            }
        }
        return {res.first, res.second};
    }
};



//  DFS Approach 

// TC - O(N+E)
// SC - O(N)


class Solution {
public:
    bool isConnected(int src, int target, vector<vector<int>>& adj, vector<bool>& visit){
        visit[src] = true;
        if(src == target) return true;
        bool isfound = false;
        for(auto node : adj[src]){
            if(!visit[node])
                isfound = isfound || isConnected(node, target, adj, visit);
        }
        return isfound;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        
        vector<vector<int>>adj(N, vector<int> {});

        for(auto edge: edges){
            vector<bool> visit(N, false);

            if(isConnected(edge[0]-1, edge[1]-1, adj, visit)){
                return edge;
            }

            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        
        return {};
    }
};