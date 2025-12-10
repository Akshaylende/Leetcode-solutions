/*
## 882. Reachable Nodes in Subdivided Graph ##


# Problem Link - 
https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
You are given an undirected graph (the "original graph") with n nodes labeled from 0 to n - 1. You decide to subdivide each edge in the graph into a chain of nodes, with the number of new nodes varying between each edge.

The graph is given as a 2D array of edges where edges[i] = [ui, vi, cnti] indicates that there is an edge between nodes ui and vi in the original graph, and cnti is the total number of new nodes that you will subdivide the edge into. Note that cnti == 0 means you will not subdivide the edge.

To subdivide the edge [ui, vi], replace it with (cnti + 1) new edges and cnti new nodes. The new nodes are x1, x2, ..., xcnti, and the new edges are [ui, x1], [x1, x2], [x2, x3], ..., [xcnti-1, xcnti], [xcnti, vi].

In this new graph, you want to know how many nodes are reachable from the node 0, where a node is reachable if the distance is maxMoves or less.

Given the original graph and maxMoves, return the number of nodes that are reachable from node 0 in the new graph.

 

# Query/ Code - 
*/
//TC - O(E+V)
//SC - O(E+N)

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, vector<pair<int, int>> >graph;
        for(auto x: edges){
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
        vector<int> dist(n, maxMoves+1);
        dist[0] = 0;
        map<pair<int, int> , int> used;
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;
        pq.push({0, 0});
        int res = 0;
        while(!pq.empty()){
           auto [distance, node] = pq.top();
           pq.pop();
           if(distance > dist[node]) continue;
           res++;
           for(auto [x, y]: graph[node]){
                used[{node, x}] = min(maxMoves - distance, y);
                if( distance + y+1 < dist[x] ){
                    pq.push({distance+y+1, x});
                    dist[x] = distance+y+1;
                }
           }
        }
        for(auto x:edges){
            res += min(x[2], used[{x[0], x[1]}]+ used[{x[1], x[0]}]);
        }
        return res; 
    }
};