/*
## 2704. To Be or Not To Be ##


# Problem Link - 
https://leetcode.com/problems/to-be-or-not-to-be/description/?envType=study-plan-v2&envId=30-days-of-javascript

# Problem Statement -
Write a function expect that helps developers test their code. It should take in any value val and return an object with the following two functions.

toBe(val) accepts another value and returns true if the two values === each other. If they are not equal, it should throw an error "Not Equal".
notToBe(val) accepts another value and returns true if the two values !== each other. If they are equal, it should throw an error "Equal".

# Query/ Code - 
*/


var expect = function(val) {
    return{
        toBe: function(vval){
            if(val === vval) return true;
            else throw new Error("Not Equal");
        },
        notToBe: function(vval){
            if(val !== vval) return true;
            else throw new Error("Equal");
        }
    };
};
 
// expect(5).toBe(5); // true
// expect(5).notToBe(5); // throws "Equal"

