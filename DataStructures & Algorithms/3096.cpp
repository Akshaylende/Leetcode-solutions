/*
## 3096. Minimum levels to gain more points ##


# Problem Link - 
https://leetcode.com/problems/minimum-levels-to-gain-more-points/description/

# Problem Statement -
You are given a binary array possible of length n.

Alice and Bob are playing a game that consists of n levels. Some of the levels in the game are impossible to clear while others can always be cleared. In particular, if possible[i] == 0, then the ith level is impossible to clear for both the players. A player gains 1 point on clearing a level and loses 1 point if the player fails to clear it.

At the start of the game, Alice will play some levels in the given order starting from the 0th level, after which Bob will play for the rest of the levels.

Alice wants to know the minimum number of levels she should play to gain more points than Bob, if both players play optimally to maximize their points.

Return the minimum number of levels Alice should play to gain more points. If this is not possible, return -1.

Note that each player must play at least 1 level.

# Query/ Code - 
*/
// TC - O(N)
// SC - O(1)

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int N = possible.size();
        int total = 0, first = 0;
        for(int i = 0; i < N; i++) total += (possible[i] == 0 ? -1 : 1);
        for(int i=0; i<N-1; i++){
            first+= (possible[i] == 0 ? -1 : 1);
            if(first > total - first)
              return i+1;
        }
        return -1;
    }
};