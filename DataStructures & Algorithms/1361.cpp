/*
## 1361. Validate Binary Tree Nodes ##


# Problem Link - 
https://leetcode.com/problems/validate-binary-tree-nodes/?envType=problem-list-v2&envId=graph

# Problem Statement -
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.


# Query/ Code - 
*/
// TC - O(N) 
// SC - O(N)


class Solution {
public:
    int find_root(int n, vector<int>& leftChild, vector<int>& rightChild){
        vector<bool>visited(n, false);
        for(int i=0; i<n; i++){
            int left  = leftChild[i];
            if(left != -1){
                if(visited[left]) return -1;
                else visited[left] = true;
            }
            int right = rightChild[i];
            if(right != -1){
                if(visited[right]) return -1;
                else visited[right] = true;
            }
        }
        int cnt = 0, res;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                cnt++;
                res = i;
            }
        }
        return cnt != 1 ? -1 : res;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1);
        int root =  find_root(n, leftChild, rightChild);
        if(root == -1) return false;
        queue<int> que;
        que.push(root);
        while(!que.empty()){
            int node = que.front();
            que.pop();
            int left = leftChild[node];
            if(left != -1){
                if(parent[left] == -1){
                    que.push(left);
                    parent[left] = node;
                }
                else if(parent[left] != node) return false;
            }
            int right = rightChild[node];
            if(right != -1){
                if(parent[right] == -1){
                    que.push(right);
                    parent[right] = node;
                }
                else if(parent[right] != node) return false; 
            }
        }
        int cnt =0 ;
        for(auto x:parent) if(x == -1) cnt++;
        return cnt != 1 ? false : true;
    }
};