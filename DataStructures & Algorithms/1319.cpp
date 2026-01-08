/*
## 1319. Number of Operations to make network connected ##


# Problem Link - 
https://leetcode.com/problems/number-of-operations-to-make-network-connected/?envType=problem-list-v2&envId=graph

# Problem Statement -
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

# Query/ Code - 
*/

// TC - O(N)
// SC - O(N)
class DisjointSet{
        vector<int> size, parent;
    public:
        DisjointSet(int nodes){
            size.resize(nodes, 1);
            parent.resize(nodes);
            for(int i=0; i<nodes; i++) parent[i] = i;
        }
        int find_parent(int node){
            if(parent[node] == node) return node;
            return parent[node]  = find_parent(parent[node]);
        }
        
        int union_by_size(int u, int v){
            int ulp = find_parent(u);
            int vlp = find_parent(v);

            if(ulp == vlp) return 1;
            
            if(size[ulp] < size[vlp]){
                parent[ulp] = vlp;
                size[vlp] += size[ulp];
            }
            else{
                parent[vlp] = ulp;
                size[ulp] += size[vlp];
            }

            return 0;
        }

        int numberofComponents(int nodes){
            int count =0; 
            for(int i = 0 ;i<nodes; i++) if(parent[i] == i) count++;
            return count;
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        for(auto x: connections){
            if(ds.union_by_size(x[0], x[1]) == 1){
                extra++;
            }
        }
        int comp = ds.numberofComponents(n)-1;
        return (extra - comp) < 0 ? -1 : comp;
    }
};