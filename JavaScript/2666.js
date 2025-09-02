/*
## 2666. Allow one Function call ##


# Problem Link - 
https://leetcode.com/problems/allow-one-function-call/description/?envType=study-plan-v2&envId=30-days-of-javascript

# Problem Statement -
Given a function fn, return a new function that is identical to the original function except that it ensures fn is called at most once.

The first time the returned function is called, it should return the same result as fn.
Every subsequent time it is called, it should return undefined.

# Query/ Code - 
*/

var once = function(fn) {
    let called = false;
    return function(...args){
        if(!called){
            called = true;
            console.log(fn(...args));
            return fn(...args);    
        }
        else return undefined;
    }
};

let fn = (a,b,c) => (a + b + c)
let onceFn = once(fn)
onceFn(1,2,3); // 6
onceFn(2,3,6); // returns undefined without calling fn
