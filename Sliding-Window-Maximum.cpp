// Source : https://leetcode.com/problems/sliding-window-maximum/
// Date   : 13-05-2022

/********************************************************************************** 

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

**********************************************************************************/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> myDeque;
        int n=nums.size();
        vector<int> result;
        
        for(int i=0; i<n; i++) {
            while(!myDeque.empty() && myDeque.back().first < nums[i]) {
                myDeque.pop_back();
            }
            
            if(myDeque.empty() || myDeque.back().first >= nums[i]) {
                myDeque.push_back({nums[i], i});
            }
            
            if(i>=k-1) {
                result.push_back(myDeque.front().first);
            }
            
            if(i-myDeque.front().second >= k-1) {
                myDeque.pop_front();
            }
        }
        
        return result;
    }
};