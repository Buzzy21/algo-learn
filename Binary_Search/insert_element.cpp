/*
TASK: Given a SORTED array of integers and a target, find the position of target in the array, if it does not exist, find the index of where target would be placed
Your program must run O(log n) time complexity*
*/

#include <bits/stdc++.h>
using namespace std;

int insertElement(vector<int> arrays, int target) {
    /*
    This is a straightforward binary search problem, if you don't know how a binary search works, it goes like this:
    The goal of the binary search is to constantly reduce the search space by half until we find the answer position,
    by doing this, we need search the MIDDLE of the search space (THE SEARCH SPACE HAS TO BE SORTED), we will adjust the searchable space after
    each search.
    To achieve this, we will keep track of a left and right pointer, where the left determines the start of the search space and right
    determines the end, we will use the formula -> left + (right - left) or (right + left) / 2  to caculate the middle index

    That will achieve finding the target for us, but what if target does not exist? In that case, binary search also got us covered,
    turns out, at the end of a binary search where the target does not exist, the left pointer will point at the closest index where
    the element should exist! 

    So simply run a BS on the array, and if target is still not found after searching through the entire search space, return the position of the left index!
    */
   
   // Initialize left and right pointers
   int left = 0, right = arrays.size()-1;

    // As long as left and right don't cross (in other words, as long as there are still a possible range of elements in the search space that could satisfy target), keep searching
   while(left <= right) {

        // Caculate middle index
       int mid = left + (right - left) / 2;

       // If the middle element is larger than target, that means the solution index must be on the left half, reduce right to mid - 1
       if(arrays[mid] > target) {
           right = mid - 1;
       }

       // If the middle element is lesser than target, that means the solution index must be on the right half, increase left to mid + 1
       else if(arrays[mid] < target) {
           left = mid + 1;
       }

       // Target found!
       else {
           return mid;
       }
   }

    // After searching through the entire array, and target is not found, return left, which is currently the closest index to where target should've been
   return left;
}