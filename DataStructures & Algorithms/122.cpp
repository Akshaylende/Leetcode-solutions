/*
## 122. Best time to buy and sell stocks II ##


# Problem Link - 
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

# Query/ Code - 
*/
/*
Approach - using variables and greedy approach 
step 1 - Initialize three variables, one for storing maximum profit while buying and selling, currprofit and current bought price
step 2 - Iterate through the prices
step 3 - check if prices[i] - current bought price < currmaxprofit and saving in maximum profit result
step 4 - reset current profit and current bought
step 5 - updating current profit at every step
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro = 0, currb = prices[0], currp = 0;
        for(int i = 0; i<prices.size(); i++){
            if(prices[i] - currb < currp){
                maxpro += currp;
                currp = 0;
                currb = prices[i];
            }
            else{
                currp = prices[i] - currb; 
            }
        }
        if(currp != 0) maxpro+=currp;
        return maxpro;
    }
};

int main(){
    cout << maxProfit([7,1,5,3,6,4]) << endl;
    return 0;
}