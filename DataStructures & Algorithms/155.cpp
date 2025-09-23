/*
## 155. Min Stack ##


# Problem Link - 
https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

# Query/ Code - 
*/

// TC - O(N)
// SC - O(N)

class MinStack {
public:
    int minele;
    vector<int> stack;

    MinStack() {
        minele = INT_MAX;
    }
    
    void push(int val) {
        minele = min(val, minele);
        stack.push_back(val);
    }
    
    void pop() {
        int size = stack.size();
        if(size > 0){
            stack.erase(stack.end());
        }
        minele = INT_MAX;
        for(int i=0;i<stack.size();i++){
            minele = min(minele, stack[i]);
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minele;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */