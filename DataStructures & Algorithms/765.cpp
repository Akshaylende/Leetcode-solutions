/*
## 765. Couples Holding Hands ##


# Problem Link - 
https://leetcode.com/problems/couples-holding-hands/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
There are n couples sitting in 2n seats arranged in a row and want to hold hands.

The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).

Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

# Query/ Code - 
*/

// TC - O(N)
// SC - O(N)


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int count =0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[row[i]] = i;
        }
        for(int i=0; i<n; i+=2){
            if(row[i]%2 == 0){
                if(mp[row[i]+1] != i+1){
                    swap(row[i+1], row[mp[row[i]+1]]);
                    count++;
                    mp[row[mp[row[i+1]]]]=mp[row[i]+1];
                    mp[row[i]+1] = i+1;
                }
            }
            else{
                if(mp[row[i]-1] != i+1){
                    swap(row[i+1], row[mp[row[i]-1]]);
                    count++;
                    mp[row[mp[row[i+1]]]] = mp[row[i]-1];
                    mp[row[i]-1] = i+1;
                }
            }
        }
        return count;
    }
};





//  Approach - 2 Disjoint Set Union


class DisjointSet{
    private:
        vector<int> size, parent;
    public:
        DisjointSet(int nodes){
            size.resize(nodes+1, 1);
            parent.resize(nodes+1);
            for(int i=0; i<=nodes; i++) parent[i] = i;
        }

        int find_parent(int node){
            if(node == parent[node]) return node;
            return parent[node] = find_parent(parent[node]);
        }

        void union_by_size(int u, int v){
            int ulp_u = find_parent(u);
            int ulp_v = find_parent(v);
            
            if(parent[ulp_u] == parent[ulp_v]) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+= size[ulp_v];
            }
        }

};


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) mp[row[i]] = i/2;
        DisjointSet ds(n/2);
        int swaps = 0;
        int u, v;
        for(int i=0; i<n;i++){
            u=row[i];
            if(row[i]%2 == 0)
                v = row[i]+1;
            else
                v = row[i]-1;

            if(ds.find_parent(mp[u]) != ds.find_parent(mp[v])){
                swaps++;
                ds.union_by_size(mp[u], mp[v]);
            } 
        }
        return swaps;
    }
};
