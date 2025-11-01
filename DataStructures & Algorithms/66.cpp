/*
## 66. plus one ##


# Problem Link - 
https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.



# Query/ Code - 
*/

// TC - O(N)
// SC - O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> plus(digits);
        int carry=0;
        for(int i=plus.size()-1;i>=0;i--)
        {
            if(i==plus.size()-1)
            {
                if(plus[i]+1>9)
                {
                    plus[i]=0;
                    carry=1;
                }
                else
                {
                    plus[i]=plus[i]+1;
                }
            }
            else if(plus[i]+carry>9)
            {
                plus[i]=0;
                carry = 1;
            }
            else
            {
                plus[i]=carry+plus[i];
                carry=0;
            }

        }
        if(carry==1)
        {
            reverse(plus.begin(), plus.end());
            plus.push_back(1);
            reverse(plus.begin(), plus.end());
        }
        return plus;
    }
};