// Source : https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
// Date   : 23-06-2023

/********************************************************************************** 

1638. Count Substrings That Differ by One Character

Given two strings s and t, find the number of ways you can choose a non-empty substring of s and 
replace a single character by a different character such that the resulting substring is a substring of t. 
In other words, find the number of substrings in s that differ from some substring in t by exactly one character.

Approach: 
    - We can count all the matching characters on the left and right. The total number of substrings will be l * r.
    - We can precompute sizes of a matching substring of left and right.

**********************************************************************************/


class Solution {
    public int countSubstrings(String s, String t) {
        int dpl[][] = new int[s.length()+1][t.length()+1];
        int dpr[][] = new int[s.length()+1][t.length()+1];

        for(int i=1; i<=s.length(); i++) {
            for(int j=1; j<=t.length(); j++) {
                if(s.charAt(i-1) == t.charAt(j-1)) {
                    dpl[i][j] = dpl[i-1][j-1]+1;
                }
            }
        }

        for(int i=s.length(); i>0; i--) {
            for(int j=t.length(); j>0; j--) {
                if(s.charAt(i-1) == t.charAt(j-1)) {
                    dpr[i-1][j-1] = dpr[i][j]+1;
                }
            }
        }

        int result = 0;
        for(int i=0; i<s.length(); i++) {
            for(int j=0; j<t.length(); j++) {
                if(s.charAt(i) != t.charAt(j)) {
                    result += (dpl[i][j]+1)*(dpr[i+1][j+1]+1);
                }
            }
        }

        return result;
    }
}