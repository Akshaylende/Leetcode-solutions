/*
## 135. Candy ##


# Problem Link - 
https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

# Query/ Code - 
*/
// Tc = O(N)
// SC = O(N)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        int count = 0;
        vector<int> prefix(N,1), suffix(N,1);
        for(int i=1;i<N;i++){
            if(ratings[i-1] < ratings[i]){
                prefix[i] = prefix[i-1]+1;
            }
            else prefix[i] = 1;
        }
        for(int i=N-2; i>=0; i--){
            if(ratings[i+1] < ratings[i]){
                suffix[i] = 1 + suffix[i+1];
            }
            else suffix[i] = 1;
        }
        for(int i = 0;i<N;i++){
            count+= max(prefix[i], suffix[i]);
        }
        return count;
    }
};

int main(){
    cout<<candy([1,0,2])<<endl;
    return 0;
}