/*
## 1368. Minimum Cost to make at least one valid path in a Grid ##


# Problem Link - 
https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=problem-list-v2&envId=graph

# Problem Statement -


# Query/ Code - 
*/
// TC - O(M*N* Log(M*N))
// SC - O(M*N)

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));
       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> >pq;
       pq.push({0, 0, 0});
       minCost[0][0] = 0;
       vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
       while(!pq.empty()){
            auto val = pq.top();
            pq.pop();
            int cost = val[0], x = val[1], y = val[2];
            
            if(minCost[x][y] != cost) continue;
            
            for(int i = 0; i < 4; i++){
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                if(newX >= 0 && newY >= 0 && newX < n && newY < m){
                    int newCost = cost + (i != (grid[x][y] -1)? 1 : 0);
                    if(minCost[newX][newY] > newCost){
                        minCost[newX][newY] = newCost;
                        pq.push({newCost, newX, newY});
                    }
                }
            }
       }
       return minCost[n-1][m-1];
    }
};