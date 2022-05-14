// Source : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// Date   : 14-05-2022

/********************************************************************************** 

Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

Input: s = "bcabc"
Output: "abc"

**********************************************************************************/

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0), isSeen(26, 0);
        
        for(int i=0; i<s.size(); i++) {
            lastIndex[s[i]-'a'] = i;
        }
        
        string result;
        
        for(int i=0; i<s.size(); i++) {
            if(isSeen[s[i]-'a']++ > 0) {
                continue;
            }
            
            while(result.size() > 0 && result.back() > s[i] && lastIndex[result.back()-'a'] > i) {
                isSeen[result.back()-'a'] = 0;
                result.pop_back();
            }
            
            result.push_back(s[i]);
        }
        
        return result;
    }
};