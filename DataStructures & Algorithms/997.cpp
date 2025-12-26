/*
## 997. Find the town Judge ##


# Problem Link - 
https://leetcode.com/problems/find-the-town-judge/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> res(n+1, 0);
        for(auto x: trust){
            res[x[0]]--;
            res[x[1]]++;
        }
        int ans =-1;
        for(int i=1; i<=n; i++){
            if(res[i] == n-1){
                if(ans != -1) return -1;
                else ans = i;
            }
        }
        return ans;
    }
};