/*
## 851. Loud and Rich ##


# Problem Link - 
https://leetcode.com/problems/loud-and-rich/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.

You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).

Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.

# Query/ Code - 
*/

// TC - O(N+E)
// SC - O(N)

class Solution {
public:
    int DFS(unordered_map<int, vector<int>>& edges, int src, vector<int>& answer, vector<int>& quiet){
        if(answer[src] != -1)
            return answer[src]; 
        answer[src] = src;
        for(auto x: edges[src]){
            int adj =  DFS(edges, x, answer, quiet);
            if(quiet[adj] < quiet[answer[src]]){
                answer[src] = adj;
            }
        }
        return answer[src];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int, vector<int>> edges;
        for(auto x: richer){
            edges[x[1]].push_back(x[0]);
        }
        vector<int> answer(n, -1);
        for(int i = 0; i<n; i++){
            if(answer[i] == -1){
                answer[i] = DFS(edges, i, answer, quiet);
            }
        }
        return answer;
    }
};