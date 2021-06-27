// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Date   : 27-06-2021

/********************************************************************************** 

Given a string s, return the longest palindromic substring in s.

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

**********************************************************************************/

class Solution {
private:
    vector<vector<int>> memo;
    
    bool dp(string &s, int i, int j, pair<int, int> &result) {
        if(i >= j) {
            return 1;
        }
        
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        
        bool found = false;
        
        if(s[i] == s[j]) {
            found = dp(s, i+1, j-1, result);
        }
        
        dp(s, i+1, j, result);
        dp(s, i, j-1, result);
        
        if(found && j-i+1 > result.second) {
            result = {i, j-i+1};
        }
    
        
        return memo[i][j] = found;
    }
    
public:
    string longestPalindrome(string s) {
        memo.resize(s.length(), vector<int>(s.length(), -1));
        
        pair<int, int> result = {0, 1};
        
        dp(s, 0, s.length()-1, result);
        
        return s.substr(result.first, result.second);
    }
};