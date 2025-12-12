/*
## 924. Minimize Malware Spread ##


# Problem Link - 
https://leetcode.com/problems/minimize-malware-spread/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
You are given a network of n nodes represented as an n x n adjacency matrix graph, where the ith node is directly connected to the jth node if graph[i][j] == 1.

Some nodes initial are initially infected by malware. Whenever two nodes are directly connected, and at least one of those two nodes is infected by malware, both nodes will be infected by malware. This spread of malware will continue until no more nodes can be infected in this manner.

Suppose M(initial) is the final number of nodes infected with malware in the entire network after the spread of malware stops. We will remove exactly one node from initial.

Return the node that, if removed, would minimize M(initial). If multiple nodes could be removed to minimize M(initial), return such a node with the smallest index.

Note that if a node was removed from the initial list of infected nodes, it might still be infected later due to the malware spread.

# Query/ Code - 
*/
// TC - O(N*N)
// SC - O(N)

class Solution {
public:
    void BFS(vector<vector<int>>& graph, int src, vector<int>& color){
        queue<int> que;
        que.push(src);
        color[src] = src;
        while(!que.empty()){
            auto node = que.front();
            que.pop();
            for(int j=0; j<graph[node].size(); j++){
                if(graph[node][j] == 1 && color[j] == -1){
                    que.push(j);
                    color[j] = src;
                }
            }
        }
    }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> color(n, -1);
        unordered_map<int, int> freq, size;
        for(int i=0; i<n; i++){
            if(color[i] == -1)
                BFS(graph, i, color);
            size[color[i]] +=1;
        }
        for(auto x: initial){
            freq[color[x]] +=1;         
        }

        int ans = INT_MAX, res = INT_MAX;
        for(auto x: initial){
            if(freq[color[x]] == 1){
                if(ans == INT_MAX){
                    ans = x;
                }
                else if(size[color[x]]> size[color[ans]])
                    ans = x;
                else if(size[color[x]] == size[color[ans]] && x< ans)
                    ans = x;
            }
            res = min(res, x);
        }
        return ans == INT_MAX ? res: ans;
    }
};



#Approach - 2 DisjointSet

class DisjointSet{
    private:
        
    public:
        vector<int> size, parent;
        DisjointSet(int capacity){
            size.resize(capacity, 1);
            parent.resize(capacity);
            for(int i =0; i < capacity; i++){
                parent[i] = i;
            }
        }

        int find_parent(int node){
            if(parent[node] == node) return node;
            return parent[node] = find_parent(parent[node]);
        }

        void union_by_size(int u, int v){
            int ulp_u = find_parent(u);
            int ulp_v = find_parent(v);
            if(ulp_u == ulp_v) return;
            
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        DisjointSet ds = DisjointSet(n);
        for(int i =0; i< n; i++){
            for(int j = 0; j<n; j++){
                if(graph[i][j] == 1)
                    ds.union_by_size(i, j);
            }
        }
        vector<int> count(n, 0);
        for(auto node : initial){
            count[ds.find_parent(node)] +=1;
        }

        int res = INT_MAX, ans = INT_MAX;
        for(auto x: initial){
            int parent = ds.find_parent(x);
            if(count[parent] == 1){
                if(res == INT_MAX) res = x;
                if(ds.size[parent] > ds.size[ds.find_parent(res)]) res = x;
                if(ds.size[parent] ==  ds.size[ds.find_parent(res)] && x < res) res = x;
            }
            ans = min(ans, x);
        }
                
        return res == INT_MAX ? ans : res;
    }
};