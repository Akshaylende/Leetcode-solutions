/*
## 427. Construct Quad Tree ##


# Problem Link - 
https://leetcode.com/problems/construct-quad-tree/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.

If you want to know more about the Quad-Tree, you can refer to the wiki.

# Query/ Code - 
*/

// TC - O(N log n)
// SC - O(N2)

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isSame(vector<vector<int>>& grid, int x, int y, int length){
        for(int i=x; i < x+length; i++){
            for(int j=y; j < y+length; j++){
                if(grid[x][y] != grid[i][j]) return false;
            }
        }
        return true;
    }
    Node* solve(vector<vector<int>>& grid, int x, int y, int length){
        if(isSame(grid, x, y, length)){
            return new Node(grid[x][y], true);
        }
        Node *root = new Node(false, false);

        root->topLeft = solve(grid, x, y, length/2);
        root->topRight = solve(grid, x, y+ length/2, length/2);
        root->bottomLeft = solve(grid, x+ length/2, y, length/2);
        root->bottomRight = solve(grid, x+ length/2, y+ length/2, length/2);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};
