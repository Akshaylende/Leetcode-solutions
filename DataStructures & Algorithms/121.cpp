/*
## 121. Best time to buy and sell stocks ##


# Problem Link - 
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

# Query/ Code - 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, buy=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            buy=min(prices[i],buy);
            ans=max(ans, prices[i]-buy);
        }
        return ans;
    }
};
//Time complexity - O(N)
space - Dyanically