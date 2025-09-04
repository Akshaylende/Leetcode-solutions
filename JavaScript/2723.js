/*
## 2723. Add two Promises ##


# Problem Link - 
https://leetcode.com/problems/add-two-promises/description/?envType=study-plan-v2&envId=30-days-of-javascript

# Problem Statement -
Given two promises promise1 and promise2, return a new promise. promise1 and promise2 will both resolve with a number. The returned promise should resolve with the sum of the two numbers.

# Query/ Code - 
*/
var addTwoPromises = async function(promise1, promise2) {
    let [val1, val2] = await Promise.all([promise1, promise2]);
    return val1 + val2;
};


 addTwoPromises(Promise.resolve(2), Promise.resolve(2))
   .then(console.log); // 4
 