/*
## 1462. Course Schedule IV ##


# Problem Link - 
https://leetcode.com/problems/course-schedule-iv/description/

# Problem Statement -
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

# Query/ Code - 
*/

// TC - O(N+E)
// SC - O(N*N)

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reach(numCourses, vector<bool>(numCourses, false));
        vector<int> adj[numCourses];
        for(auto x: prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        queue<pair<int, int>> que;

        for(int i=0; i<numCourses; i++){
            
            que.push({i, i});
        }
        while(!que.empty()){
            auto [course, par] = que.front();
            que.pop();
            reach[par][course] = true;
            for(auto x: adj[course]){
                if(!reach[par][x]){
                    que.push({x, par}); 
                    reach[par][x] = true;
                }
            }
        }

        vector<bool> results;
        for(auto x: queries){
            if(reach[x[0]][x[1]]) results.push_back(true);
            else results.push_back(false);
        }
        return results;
    }
};