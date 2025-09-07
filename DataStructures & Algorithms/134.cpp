/*
## 134. Gas Station ##


# Problem Link - 
https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

 

# Query/ Code - 
*/
// TC - O(N)
// SC - O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int total_gas = 0, total_cost = 0;
        int curr_gas = 0;
        for(int i=0; i<gas.size(); i++){
            total_cost += cost[i];
            total_gas += gas[i];
            curr_gas += gas[i] - cost[i];
            if(curr_gas < 0){
                curr_gas = 0;
                start = i+1; 
            }
        }
        return total_cost > total_gas ? -1 : start;
    }
};

int main(){
    cout<< canCompleteCircuit([1,2,3,4,5],[3,4,5,1,2])<< endl;
    return 0;
}