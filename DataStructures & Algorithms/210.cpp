/*
## 210. Course Schedule II ##


# Problem Link - 
https://leetcode.com/problems/course-schedule-ii/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

# Query/ Code - 
*/
// TC - O(N+E)
// SC - O(N)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topos, indegree(numCourses, 0);
        unordered_map<int, vector<int> >edges;
        for(auto x: prerequisites){
            edges[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topos.push_back(node);
            for(auto x: edges[node]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        if(topos.size() != numCourses)   return {};
       return topos;
    }
};