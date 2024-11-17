/*

TASK: Given an array of integer nums, and N queries each consisting of two values L and R, output the subarray sum from nums[l] up to 
and including nums[r]

*/

#include <bits/stdc++.h> // <- Beware!
using namespace std;

void sumQueries(vector<int> nums, vector<pair<int,int>> queries) {
    /*
    One brute force way to solve this is to manually compute each query by actually summing the numbers between L-R, however, this is inefficient and
    might become too slow, there is a much cleaner and efficient way to do this, the technique which allows us to achieve this is called "prefix sum."
    Imagine this, you have a snowballed array, meaning that the current sum is equal to sum of all number before and including it, meaning that the last index will
    contain the entire sum of the array and the second to last index will contain the entire sum excluding the last index of the array, this means that for every
    query where L = 0, we can simply output prefix_nums[R], we can also use this logic to compute the query when L > 0 by simply "shaving off" the unneeded sums by using this formula:
    prefix_nums[R] - prefix_nums[L-1], this subtracts the entire sum up to and including R by the prefix sum right before L, which gives us the just needed sum.
    */

    // Build prefix sum
    for(int i = 1; i < nums.size(); i++) {
        // Add the current number by the last, this will "snowball" the last value onto the current
        nums[i] += nums[i-1];
    }

    // Compute the queries
    for(pair<int,int> query : queries) {
        // Get L and R
        int l = query.first;
        int r = query.second;
        
        // The formula for a query is: Sum up to and including position R - sum up to L (take the entire sum, and "shave off" the extra)
        cout << nums[r] - nums[l-1] << endl;
    }
}