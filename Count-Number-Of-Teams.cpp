// Source : https://leetcode.com/problems/count-number-of-teams/
// Date   : 20-02-2021

/********************************************************************************** 

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

**********************************************************************************/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int totalTeams = 0;
        
        for(int i=1; i<rating.size()-1; i++) {
            int leftLess = 0, rightGreater = 0;
            int leftGreater = 0, rightLess = 0;
            
            //left
            for(int j=i-1; j>=0; j--) {
                if(rating[j] < rating[i])
                    leftLess++;
                if(rating[j] > rating[i])
                    leftGreater++;
            }
            
            //right
            for(int j=i+1; j<rating.size(); j++) {
                if(rating[j] < rating[i]) 
                    rightLess++;
                if(rating[j] > rating[i])
                    rightGreater++;
            }
            
            totalTeams += (leftLess*rightGreater)+(leftGreater*rightLess);
        }
        
        return totalTeams;
    }
};