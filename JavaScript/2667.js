/*
## 2667. Create Hello World Function ##

# Problem Link - 
https://leetcode.com/problems/create-hello-world-function/description/?envType=study-plan-v2&envId=30-days-of-javascript

# Problem Statement -
Write a function createHelloWorld. It should return a new function that always returns "Hello World".

# Code - 
*/

var createHelloWorld = function(){
    return function(...args){
        return "Hello World";
    }
}


const f = createHelloWorld();
f();
// console.log(f());

