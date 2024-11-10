/*

TASK: Given an array of n integers, return an integer, representing the amount of unique integers that is present in the array

*/

#include <bits/stdc++.h> // <- Beware!
using namespace std;

int unique_nums(vector<int> nums) {
    /*
    What if there is a data structure that stores only unique items? That's a set! Simply copy the elements from nums onto
    a set data structure, and return the size of that set.
    */
    
    set<int> st;
    
    //Move the elements from the array to the set
    for(int i = 0; i < nums.size(); i++) {
        st.insert(nums[i]);
    }
    // Alternatively, you could just do:
    // set<int> st(nums.begin(),nums.end()); during the initialization of the set

    return st.size();
}