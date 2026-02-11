/*
## 9. Palindrome Number ##


# Problem Link - 
https://leetcode.com/problems/palindrome-number/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Given an integer x, return true if x is a palindrome, and false otherwise.



# Query/ Code - 
*/
// TC - O(N)
// SC - O(N)

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        vector<int> aksha;
        int n = x;
        while(n>0)
        {
            aksha.push_back(n%10);
            n=n/10;
        }
        int i=0, j=aksha.size()-1;
        while(i<j)
        {
            if(aksha[i]!=aksha[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


// Approach
1. Add the digits into a vector or container. 
2. using a loop iteration and two pointers one at the start and the second at the end
3. check  if the values at two pointers differ? and return accordingly. 