/*
## 2634. Filter Elements from Array ##


# Problem Link - 
https://leetcode.com/problems/filter-elements-from-array/description/?envType=study-plan-v2&envId=30-days-of-javascript

# Problem Statement -
Given an integer array arr and a filtering function fn, return a filtered array filteredArr.

The fn function takes one or two arguments:

arr[i] - number from the arr
i - index of arr[i]
filteredArr should only contain the elements from the arr for which the expression fn(arr[i], i) evaluates to a truthy value. A truthy value is a value where Boolean(value) returns true.

Please solve it without the built-in Array.filter method.

# Query/ Code - 
*/

var filter = function(arr, fn) {
    let res = [];
    arr.forEach((ele, ind) => {
        if(fn(ele, ind)){
            res.push(ele);
        }
    })
    return res;
};

let fn = function firstIndex(n, i){ 
    return i === 0;
}
console.log(filter([1, 2, 3], fn));