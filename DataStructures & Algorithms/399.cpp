/*
## 399. Evaluate Division ##


# Problem Link - 
https://leetcode.com/problems/evaluate-division/?envType=problem-list-v2&envId=graph

# Problem Statement -
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

# Query/ Code - 
*/
TC - O(N+Mlogn)
SC - O(3V)

class Solution {
public:
    double find_solution(unordered_map<string, vector<pair<string, double>>>& edges, string src, string dest){
        unordered_map<string, double> distance;
        for(auto [x,y]: edges){
            distance[x] = DBL_MAX;
        }
        priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>> > pq;
        pq.push({1.0, src});
        distance[src] = 1.0;
        while(!pq.empty()){
            auto [value, node] = pq.top();
            pq.pop();
            if(node == dest){
                return value;
            }
            for(auto [x, y] : edges[node]){
                if(value*y < distance[x]){
                    distance[x] = value*y;
                    pq.push({distance[x], x});
                }
            }
            
        }
        
        return distance[dest] == DBL_MAX ? -1.0 : distance[dest];
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector< pair<string, double>>> edges;
        int n = equations.size();
        for(int i=0; i<n; i++){
            edges[equations[i][0]].push_back({equations[i][1], values[i]});
            edges[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        vector<double> solution;
        for(auto query: queries){
            if(edges.find(query[0]) == edges.end() || edges.find(query[1]) == edges.end()){
                solution.push_back(-1.0);
                continue;
            }
            solution.push_back(find_solution(edges, query[0], query[1]));
        }
        return solution;
    }
};