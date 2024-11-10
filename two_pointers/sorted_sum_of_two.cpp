/*

TASK: Given a SORTED array of n integers and an integer target, return a pair of indicies from the array that adds up to target
THIS IS ALSO KNOWN AS TWO SUM 

*/

#include <bits/stdc++.h> // <- Beware!
using namespace std;

pair<int,int> sumOfTwoSorted(vector<int> nums, int target) {
    /*
    There are multiple ways to solve this problem, but for the purpose of this tutorial, we will refer to the two pointer method, 
    note that this IS NOT the most optimal way to solve this problem as it requires prior-sorting.

    An intuitive way of solving this problem is to have a left and right pointer, left pointing at the very first
    index of the array (0) and right pointing at the very end of the array (n-1), what ALWAYS happens if we decrement the right pointer?
    (In other words, what happens if we move the right pointer to the left?), and vice versa? 
    
    It turns out, whenever we move the right pointer leftwards, the sum of nums[l] + nums[r] decreases, when the left pointer moves rightwards,
    the sum increases. Meaning that we can simply keep track of the two pointers, and move the left and right pointers accordingly until we find the solution.

    If the pointers ever cross each other, then there will be no solutions, so we will search as long as (l < r)
    Also note that this solution only works if the array is sorted*
    */
    
    // Initialize the left pointer at index 0, and right index at n-1 (the final element of the array)
    int l = 0, r = nums.size()-1;

    // The pointers should never cross each other
    while(l < r) {

        int sum = nums[l] + nums[r];

        // If the total sum is greater than target, move r to the left, if the sum is lesser, move l to the right, if the sum is equal to target, then just return the solution
        if(sum > target) r--;
        else if(sum < target) l++;
        else {
            return {l,r};
        }
    }
    
    // No solution available
    return {-1,-1};
}