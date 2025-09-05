/*
## 88. Merge Sorted Arrays ##


# Problem Link -
https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

# Problem Statement -
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

# Query/ Code - */
// Write your code below this: - 
# Time Complexity - O(N log(m+n))

# Space Complexity - O(m+n)

#include<bits/stdio.h>
using namespace std; 


class Solution {
public:
    vector<int> mySort(vector<int>& myArray){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x :myArray){
            pq.push(x);
        }
        int ii = 0;
        while(!pq.empty() && ii < myArray.size()){
            auto x = pq.top();
            pq.pop();
            myArray[ii++] = x;
        }
        return myArray;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(auto ii = m; ii < m+n; ii++){
            nums1[ii] = nums2[ii-m];
        }
        mySort(nums1);
    }
};


void Show(vector<int>& nums){
    for(auto x : nums){
        cout<< x << " ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums1([1, 2, 3, 0, 0, 0]), nums2([4, 5, 6];
    // Edit your main code here 

    mySort(nums1, nums2);

    Show(nums1);
    return 0;
}


###### Approach - 2 ########
/*
optimized Approach - 
step 1 - using two pointers approach and declaring a variable to k to reference a position in the nums1[] array 
step 2 - placing i on m-1 and j on n-1 and k on the end of the array and starts traversing from the end to start. 
Step 3 - Comparing i && j indexed variable at every step and deciding the values for index k till the start of the array. 

TC - O(m+n)
SC - O(1)

*/



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m+n-1, i = m-1, j=n-1;
        //
        while((i >= 0 && j>=0)){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                nums1[i]=0;
                i--;
            }
            else{ 
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};