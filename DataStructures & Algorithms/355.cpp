/*
## 355. Design Twitter ##


# Problem Link - 
https://leetcode.com/problems/design-twitter/description/

# Problem Statement -
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

# Query/ Code - 
*/

// TC - O(N log N)
// SC - O(N) 


class Twitter {
    int time;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> connections;
public:
    Twitter() {
      this->time = 0;  
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time});
        time++;
   }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto follower: connections[userId]){
            for(auto tweet: tweets[follower]){
                pq.push({tweet.second, tweet.first});
            }
        }
        for(auto tweet: tweets[userId]){
            pq.push({tweet.second, tweet.first});
        }
        vector<int> feed;
        while(!pq.empty()){
            feed.push_back(pq.top().second);
            pq.pop();
            if(feed.size()==10) break;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        connections[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        connections[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */