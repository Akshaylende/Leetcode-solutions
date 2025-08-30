/*
## 2626. Array Reduce Transformation ##


# Problem Link - 
https://leetcode.com/problems/array-reduce-transformation/description/?envType=study-plan-v2&envId=30-days-of-javascript

# Problem Statement -
Given an integer array nums, a reducer function fn, and an initial value init, return the final result obtained by executing the fn function on each element of the array, sequentially, passing in the return value from the calculation on the preceding element.

This result is achieved through the following operations: val = fn(init, nums[0]), val = fn(val, nums[1]), val = fn(val, nums[2]), ... until every element in the array has been processed. The ultimate value of val is then returned.

If the length of the array is 0, the function should return init.

Please solve it without using the built-in Array.reduce method.

# Query/ Code - 
*/
var reduce = function(nums, fn, init) {
    let res = init;
    nums.forEach((ele, ind)=> {
        res = fn(res, ele);
    })
    return res;
};

console.log(reduce([1,2,3,4], function sum(accum, curr) { return accum + curr; }, 0));