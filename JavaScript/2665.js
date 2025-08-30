/*
## 2665. Counter 11 ##


# Problem Link - 
https://leetcode.com/problems/counter-ii/description/?envType=study-plan-v2&envId=30-days-of-javascript

# Problem Statement -
Write a function createCounter. It should accept an initial integer init. It should return an object with three functions.

The three functions are:

increment() increases the current value by 1 and then returns it.
decrement() reduces the current value by 1 and then returns it.
reset() sets the current value to init and then returns it.

# Query/ Code - 
*/
var createCounter = function(init) {
    let val = init;

    function increment(){
        return ++val;
    }
    
    function decrement(){
        return --val;
    }
    function reset(){
        return (val = init);
    }
    return {increment, decrement, reset};
};

const counter = createCounter(5)
counter.increment(); // 6
counter.reset(); // 5
counter.decrement(); // 4
 