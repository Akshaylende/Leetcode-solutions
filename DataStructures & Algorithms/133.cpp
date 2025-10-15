/*
## 133. Clone Graph ##


# Problem Link - 
https://leetcode.com/problems/clone-graph/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> reference;
        queue<Node*> q;
        unordered_set<Node*> visit;
        if(!node) return node;
        q.push(node);
        visit.insert(node);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            auto curr2 = new Node(curr->val);
            reference[curr->val] = curr2;
            for(auto adj : curr->neighbors)
            {
                if(visit.find(adj) == visit.end()){
                    q.push(adj);
                    visit.insert(adj);
                }
            }
        }
        q.push(node);
        visit.clear();
        visit.insert(node);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto adj : curr->neighbors){
                reference[curr->val]->neighbors.push_back(reference[adj->val]);
                if(visit.find(adj) == visit.end()){
                    q.push(adj);
                    visit.insert(adj);
                } 
            }
        }
        return reference[node->val];
    }
};