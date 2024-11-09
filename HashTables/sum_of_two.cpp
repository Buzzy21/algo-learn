/*

TASK: Given an array of n integers and an integer target, return a pair of indicies from the array that adds up to target
THIS IS ALSO KNOWN AS TWO SUM 

*/

#include <bits/stdc++.h> //<- beware!
using namespace std;

pair<int,int> sumOfTwo(vector<int> nums, int target) {

    /* At first, it might seem obvious that we could nest two loops and check every possible pair of integers,
    but what if the input becomes too large for nested loop? 
    
    There is a much more efficient solution, one way to think of it is that the problem would become much easier if we could 
    simply check if there is another number that complements "this" number, so that we only need to check each number 
    once, in other words, we iterate through each element, and then check if there is a "complementary" 
    element that will sum to target

    This can be done with the help of a Map, a key-value data structure which allows instant searching
    */

   unordered_map<int,int> mp;
   
   int N = nums.size();

   for(int i = 0; i < N; i++) {
       int current = nums[i];

       // The element we are looking for
       int complement = target - current;
       
       // If the map does contain the complement, AKA. if there is a match, we return that match
       if(mp.find(complement) != mp.end()) {
           return {i, mp[complement]};
       }

       // Place the current element in map (mp[value] = index)
       mp[current] = i;
   }

   return {-1,-1};
}

// The time complexity for this algorithm is O(n)