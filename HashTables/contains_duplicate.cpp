/*

TASK: Given an array of n integers, return true if there is a duplicate element, otherwise return false

*/

#include <bits/stdc++.h>
using namespace std;


bool containsDup(vector<int> nums) {
    /* 
    Your first intuition might be to use nested loops, checking every pair of element looking for a duplicate, but like always, O(n^2) 
    could become too slow when the input size becomes too large. 

    One way to solve this problem is to traverse through the array, and have a data structure that stores the "appeared" elements,
    and for each element, we check if they already exists in that data structure, if they do, then they have appeared.

    Sets are great at handling storing items and searching due to its constant look-up time
    */

   unordered_set<int> st; //PS. Unordered and ordered sets does not matter for this problem, but keep in mind that an ordered set is simply a set that is always sorted

    /*
    For each element we will check if they already exists in the set, if they do, return false,
    otherwise, insert them to the set, so the next time it appears, we will return false.
    */

   for(int i = 0; i < nums.size(); i++) {
       // Check if we have already seen this element
       if(st.find(nums[i]) != st.end()) {
           return false;
       }
       
       // Next time we see this element, we will return false
       st.insert(nums[i]);
   }

   return true;
}