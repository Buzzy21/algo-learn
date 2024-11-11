/*

TASK: Given two strings, return true if they are anagrams of each other, return false otherwise.
(An anagram is a word or phrase formed by rearranging the letters of a different word or phrase)

*/

#include <bits/stdc++.h> // <- Beware!
using namespace std;

bool isAnagram(string a, string b) {
    /*
    This problem might be hard to grasp on until you observe one thing, two strings are anagrams IF AND ONLY IF they have the same
    variation and count of letters, in other words, if string A has 2 Zs, 3 Cs, and 1 Ls, then string B MUST also have 2 Zs, 3 Cs, and 1 Ls, 
    counting the letters of each string is trivial, as it could be done both with a map or an array, for the sake of this, we will use an array.
    */

    // Create two arrays with size of 26, each index will be responsible for one letter of the alphabet, and the value of that index is the count.
    // Technically this is not a hashtable, but the concept is extremely similar and the implementation with hashtables is fairly similar to this.
    vector<int> aCount(26,0); 
    vector<int> bCount(26,0);

    // Count the characters of string A
    for(char c : a) {
        aCount[c - 'a']++; // Use - 'a' because the ASCII (AKA. the integer version of a char) does not start at 0, but simply subtracting by 'a' will give us the exact index we need
    }
    
    // Repeat for string B
    for(char c : b) {
        bCount[c - 'a']++;
    }

    // Check if the counts are equal
    for(int i = 0; i < 26; i++) {
        // If the counts differ, then they are not anagrams.
        if(aCount[i] != bCount[i]) return false;
    }
    
    return true;
}