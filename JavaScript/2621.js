/*
## 2621. Sleep ##


# Problem Link - 
https://leetcode.com/problems/sleep/description/?envType=study-plan-v2&envId=30-days-of-javascript

# Problem Statement -
Given a positive integer millis, write an asynchronous function that sleeps for millis milliseconds. It can resolve any value.

Note that minor deviation from millis in the actual sleep duration is acceptable.

# Query/ Code - 
*/
async function sleep(millis) {
    return new Promise(resolve => setTimeout(resolve, millis));
}

 
let t = Date.now()
sleep(100).then(() => console.log(Date.now() - t)) // 100
 