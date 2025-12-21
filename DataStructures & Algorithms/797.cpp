/*
## 797. All paths from Source to Target ##


# Problem Link - 
https://leetcode.com/problems/all-paths-from-source-to-target/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).


# Query/ Code - 
*/
// TC - O(N*E) 
// SC - O(N)

class Solution {
public:
    void DFS(vector<vector<int>>& graph, int node, int dest, vector<bool> visit, vector<vector<int>>& paths, vector<int> curr){
        if(node == dest){
            paths.push_back(curr);
            return; 
        }
       
            visit[node] = true;
            for(auto adj: graph[node]){
                if(!visit[adj]){
                    curr.push_back(adj);
                    DFS(graph, adj, dest, visit, paths, curr);
                    curr.pop_back();
                }
            }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        vector<bool>visit(n, false);
        DFS(graph, 0, n-1, visit, paths, {0});
        return paths;
    }
};