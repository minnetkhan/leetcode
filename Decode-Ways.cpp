// Source : https://leetcode.com/problems/decode-ways/
// Date   : 18-05-2022

/********************************************************************************** 

91. Decode Ways

Input: s = "226"
Output: 3

**********************************************************************************/

// recursive solution...
class Solution {
public:
    int recursion(string &s, int pos, vector<int> &memo) {
        if(pos == s.size())
            return 1;
        
        if(s[pos] == '0')
            return 0;
        
        if(memo[pos] != -1)
            return memo[pos];
        
        int res = recursion(s, pos+1, memo);
        
        if(pos+1<s.size() && (s[pos] == '1' || (s[pos] == '2' && s[pos+1] < '7'))) {
            res += recursion(s, pos+2, memo);
        }
        
        return memo[pos] = res;
    }
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        
        return recursion(s, 0, memo);
    }
};


// iterative solution
class Solution { // 0 ms, faster than 100.00%
public:
    int numDecodings(const string& s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') // Single digit
                dp[i] += dp[i+1];
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};