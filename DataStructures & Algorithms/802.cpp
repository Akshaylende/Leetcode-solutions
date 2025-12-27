/*
## 802. Find Eventual Safe States ##


# Problem Link - 
https://leetcode.com/problems/find-eventual-safe-states/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

# Query/ Code - 
*/

// TC - O(NE)
// SC - O(N)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        vector<int> indegree(n, 0);
        vector<int> edges[n];
        for(int i=0; i<graph.size();i++)
        {
            for(auto x: graph[i])
            {
                edges[x].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())   
        {
            auto x = q.front();
            q.pop();
            res.push_back(x);
            for(auto adj : edges[x])
            {
                indegree[adj]--;
                if(indegree[adj]==0) q.push(adj);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};