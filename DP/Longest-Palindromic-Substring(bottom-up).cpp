// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Date   : 27-06-2021

/********************************************************************************** 

Given a string s, return the longest palindromic substring in s.

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

**********************************************************************************/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        vector<vector<int>> memo(n, vector<int>(n, 0));
        
        int pos=0, len=1;
        
        for(int i=0; i<n; i++) {
            memo[i][i] = 1;
        }
        
        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                memo[i][i+1] = 1;
                pos = i;
                len = 2;
            }
        }
        
        for(int k=3; k<=n; k++) {
            for(int i=0; i<n-k+1; i++) {
                int j = i+k-1;
                
                if(s[i] == s[j] && memo[i+1][j-1]) {
                    memo[i][j] = 1;
                    
                    if(len < j-i+1) {
                        len = j-i+1;
                        pos = i;
                    }
                }
            }
        }
        
        return s.substr(pos, len);
    }
};