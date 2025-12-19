/*
## 547. Number of Provinces ##


# Problem Link - 
https://leetcode.com/problems/number-of-provinces/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

# Query/ Code - 
*/
// TC - O(N*N)
// SC - O(N)

class DisJointSet{
    vector<int> size, parent;
    public:
    DisJointSet(int nodes){
        size.resize(nodes, 1);
        parent.resize(nodes);
        for(int i=0; i<nodes; i++) parent[i] = i;
    }
    int find_parent(int node){
        if(parent[node] == node) return node;
        return parent[node] = find_parent(parent[node]);
    }

    void union_by_size(int u, int v){
        int uPu = find_parent(u);
        int uPv = find_parent(v);
        if(uPu == uPv) return;
        if(size[uPu] < size[uPv]){
            size[uPv] += size[uPu];
            parent[uPu] = uPv;
        }
        else{
            parent[uPv] = uPu;
            size[uPu] += size[uPv];
        }
    }
    int calculate_provinces(){
        int sol = 0;
        for(int i=0; i<parent.size(); i++){
            if(parent[i] == i ) sol++;
        }
        return sol;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisJointSet ds(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    ds.union_by_size(i, j);
                }
            }
        }
        return ds.calculate_provinces();
    }
};