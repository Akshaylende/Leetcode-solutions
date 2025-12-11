/*
## 207. Course Schedule ##


# Problem Link - 
https://leetcode.com/problems/course-schedule/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

# Query/ Code - 
*/
// TC - O(N+E)
// SC - O(N)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;
        vector<int> indegree(numCourses, 0), topos;
        for(auto x: prerequisites){
            edges[x[0]].push_back(x[1]);
            indegree[x[1]]+=1;
        }
        queue<int> que;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0) que.push(i);
        }
        while(!que.empty()){
            int node = que.front();
            que.pop();
            topos.push_back(node);
            for(auto x: edges[node]){
                indegree[x]--;
                if(indegree[x] == 0) que.push(x);
            }
        }
        return topos.size() == numCourses ? true: false;
    }
};