/*
## 1311. Get Watched Videos by Your Friends ##


# Problem Link - 
https://leetcode.com/problems/get-watched-videos-by-your-friends/description/?envType=problem-list-v2&envId=graph

# Problem Statement -
There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

# Query/ Code - 
*/
//TC - O(N + Mlog(M))
//SC - O(N)

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> res;
        unordered_map<string, int> mp;
        int n = friends.size();
        vector<bool> visit(n, false);
        queue<pair<int, int>>que;
        que.push({id, level});
        visit[id] = true;
        while(!que.empty()){
            auto [node, levl] = que.front();
            que.pop();
            levl--;
            if(levl  == -1){
                for(auto x:watchedVideos[node]){
                    mp[x]+=1;
                }
                continue;
            }
            for(auto x: friends[node]){
                if(!visit[x]){
                    que.push({x, levl});
                    visit[x]=true;
                }
                
            }
        } 
        vector<pair<int, string> > temp;
        for(auto [x, y]: mp){
           temp.push_back({y, x});
        }
        sort(temp.begin(), temp.end());
        for(auto [x, y]: temp){
            res.push_back(y);
        }
        return res; 
    }
};