/*
## 117. Populating Next Right Pointers in Each Node II ##


# Problem Link - 
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL

# Query/ Code - 
*/
/*
// TC - O(N)
// SC - O(N)

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node* > que;
        if(root) que.push(root);
        que.push(NULL);
        while(!que.empty()){
            auto curr = que.front();
            que.pop();
            if(curr){
                curr->next = que.front();
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            else{ 
                if(!que.empty()) que.push(NULL);
            }
        }
        return root;   
    }
};