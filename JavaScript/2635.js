/*
## 2635. Apply Transform over each Element in Array ##


# Problem Link - 
https://leetcode.com/problems/apply-transform-over-each-element-in-array/description/?envType=study-plan-v2&envId=30-days-of-javascript

# Problem Statement -
Given an integer array arr and a mapping function fn, return a new array with a transformation applied to each element.

The returned array should be created such that returnedArray[i] = fn(arr[i], i).

Please solve it without the built-in Array.map method.


# Query/ Code - 
*/
var map = function(arr, fn) {
    const newArray = [];
    arr.forEach((ele, ind)=>{
        newArray[ind] = fn(ele, ind);
    });
    return newArray;
};

console.log(map([2,3,4], function plusI(n, i) { return n + i; }))
;
