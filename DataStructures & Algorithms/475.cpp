/*
## 475. Heaters ##


# Problem Link - 
https://leetcode.com/problems/heaters/description/?envType=problem-list-v2&envId=binary-search

# Problem Statement -
Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
Every house can be warmed, as long as the house is within the heater's warm radius range. 
Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
Notice that all the heaters follow your radius standard, and the warm radius will be the same.

# Query/ Code - 
*/
// TC - O((M+N)log R)
// SC - O(1)
class Solution {
public:
    bool isvalid(vector<int>& houses, vector<int>& heaters, int& rad){
        int i=0, j=0;
        while(i<houses.size() && j<heaters.size()){
            if(abs(houses[i]-heaters[j])<= rad) i++;
            else j++;
        }
        return i == houses.size();
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        int low = 0;
        int high = 1e9;
        int radius = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isvalid(houses, heaters, mid)){
                radius = mid;
                high = mid -1;
            }
            else low = mid+1;
        }
        return radius;
    }
};