/*
## 502. IPO ##


# Problem Link - 
https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

# Query/ Code - 
*/
// TC - O(n logn) + O(K logn)
// SC - O(n)

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pairs;
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            pairs.push({capital[i], profits[i]});
        }
        for(int i=0; i<k; i++){
            while(!pairs.empty() && pairs.top().first <= w){
                pq.push(pairs.top().second);
                pairs.pop();
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};