// Source : https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Date   : 02-03-2021

/********************************************************************************** 

You are given two arrays of integers nums1 and nums2, possibly of different lengths. 
The values in the arrays are between 1 and 6, inclusive.

In one operation, you can change any integer's value in any of the arrays to any value between 1 and 6, inclusive.

Return the minimum number of operations required to make the sum of values in nums1 equal to the sum of values in nums2. 
Return -1​​​​​ if it is not possible to make the sum of the two arrays equal.

Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
- Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
- Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
- Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].

**********************************************************************************/

/********************************************************************************** 

Intuition

We can increase sum of the smaller array up 5 per move (if we have 1 in there).
We can decrease sum of the larger array up to 5 points per move (if we have 6 there).

Solution - Heap

Use min heap for the smaller, and max heap for larger arrays.
Pull a value from one of the heaps; pick a heap that would give us the most points.
Repeat till the sum of two arrays is equalized.

**********************************************************************************/

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size()*6 < nums2.size() || nums2.size()*6 < nums1.size() ) {
            return -1;
        }
        
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        
        if(sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }
        
        //min heap
        priority_queue<int, vector<int>, greater<int>> q1(nums1.begin(), nums1.end());
        
        // max heap
        priority_queue<int> q2(nums2.begin(), nums2.end());
        
        
        int diff = sum2-sum1;
        int count = 0;
        
        while(diff > 0) {
            if( q1.empty() || (!q2.empty() && (q2.top()-1 > 6-q1.top()) ) ) {
                diff = diff - (q2.top()-1);
                q2.pop();
            }
            else {
                diff = diff - (6-q1.top());
                q1.pop();
            }
            
            count++;
        }
        
        return count;
    }
};