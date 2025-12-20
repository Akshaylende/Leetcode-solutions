/*
## 743. Network Delay Time ##


# Problem Link - 
https://leetcode.com/problems/network-delay-time/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

# Query/ Code - 
*/

// TC - O((N+E)* Nlog(E))
// SC - O(N)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>> > edges;
        for(auto x: times){
            edges[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto [step, node] = pq.top();
            pq.pop();
            if(step > time[node]) continue;
            for(auto [x, y]: edges[node]){
                if(step+y < time[x]){
                    time[x]  = step+y;
                    pq.push({time[x], x});
                }
            }
        }

        int minTime = 0;
        for(int i=1; i<=n; i++){
            if(time[i] == INT_MAX) return -1;
            minTime = max(minTime, time[i]);
        }
        return minTime;
    }
};