// Source : https://leetcode.com/problems/minimum-window-substring/
// Date   : 18-02-2022

/********************************************************************************** 

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
**********************************************************************************/

/********************************************************************************** 

Intuition:
**********************************************************************************/

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> hash;
        
        for(char ch: t) hash[ch]++;
        int countLetters = 0;
        int minLength = INT_MAX, start=0, lo=0;
        
        for(int hi=0; hi<s.size(); hi++) {
            if(hash[s[hi]] > 0) countLetters++;
            hash[s[hi]]--;
            
            if(countLetters == t.size()) {
                while(lo<hi && hash[s[lo]] < 0) {
                    hash[s[lo]]++;
                    lo++;
                }
                
                if(minLength > hi-lo) {
                    minLength = hi-lo+1;
                    start = lo;
                }
                
                hash[s[lo]]++;
                lo++;
                countLetters--;
            }
        }
        
        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};