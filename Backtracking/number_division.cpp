/*
TASK: Given an array of n (0 < n < 20) integers, divide the numbers into two groups, return the minimal sum difference you can achieve after 
dividing the numbers into two groups where each
*/

#include <bits/stdc++.h> // <- Beware!
using namespace std;


/*
Since n can only be up to 20, we can resort to a brute force approach to solve this problem. How can we generate all possible
pairs of groups?

In this case, we can recursively generate all pairs of groups, the groups will be the "subsets" of the array, in other words, each recursive call,
we will generate two more calls, one where the current element is added to group A, and another call where the current element is added to group B.
At the end of all the calls, we should have iterated through every element of the array, and in that case, we will update the answer variable accordingly
*/


// Create answer variable outside of main function so it can be accessed from anywhere
int ans = INT_MAX;

void search(int index, int aSum, int bSum, vector<int>& nums) {
    // If all elements have been iterated, then update ans
    if(index == nums.size()) {
        ans = min(ans, abs(aSum - bSum));
        return;
    }

    // Create a new call where group A will include the current number
    search(index+1, aSum + nums[index], bSum, nums);

    //Create a new call where group B will include the current number
    search(index+1, aSum, bSum + nums[index], nums);
    
    return;
}

int num_division(vector<int> nums) {
    // Kickstart recursion
    search(0, 0, 0, nums);
    
    return ans;
}