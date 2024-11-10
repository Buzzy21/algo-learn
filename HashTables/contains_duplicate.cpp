/*

TASK: Given an array of n integers, return true if there is a duplicate element, otherwise return false

*/

#include <bits/stdc++.h>
using namespace std;


bool containsDup(vector<int> nums) {
    /* Your first intuition might be to use nested loops, checking every pair of element looking for a duplicate, but like always, O(n^2) 
    could become too slow when the input size becomes too large, in this case, we can use sets to make this problem trivial. 
    */

   unordered_set<int> st; //PS. Unordered and ordered sets does not matter for this problem, but keep in mind that an ordered set is simply a set that is always sorted

    /*
    For each element we will check if they already exists in the set, if they do, return false,
    otherwise, insert them to the set, so the next time it appears, we will return false.
    */

   for(int i = 0; i < nums.size(); i++) {
       //check if we have already seen this element
       if(st.find(nums[i]) != st.end()) {
           return false;
       }
       
       //next time we see this element, we will return false
       st.insert(nums[i]);
   }

   return true;
}