/*
## 1192. Critical Connections in a Network ##


# Problem Link - 
https://leetcode.com/problems/critical-connections-in-a-network/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

# Query/ Code - 
*/
// TC - O(V+2E)
// SC - O(N2)

class Solution {
    int time = 0;
public:
    void DFS(unordered_map<int, vector<int>>& adj, int node, int parent, vector<bool>& visited, vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges){
        visited[node] = true;
        tin[node] = low[node] = time;
        time++;
        
        for(auto x: adj[node]){
            if(x == parent) continue;
            if(!visited[x]){
                DFS(adj, x, node, visited, tin, low, bridges);
                low[node] = min(low[node], low[x]);
                if(tin[node] < low[x]){
                    bridges.push_back({node, x});
                }
            }
            else{
                low[node] = min(low[node], low[x]);
            }
           
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        unordered_map<int, vector<int>> adj;
        for(auto x: connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n, false);
        vector<int>tin(n), low(n);
        DFS(adj, 0, -1, visited, tin, low, bridges);
        return bridges;
    }
};