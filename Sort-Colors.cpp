// Source : https://leetcode.com/problems/sort-colors/
// Date   : 17-02-2022

/********************************************************************************** 

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

**********************************************************************************/

/********************************************************************************** 
Intuition:
Take 3 pointer: low, mid and high
Ensure all values before low is 0 and all values after high is 2.
Mid is unprocessed it can be anything [0,1,2].
If mid is 0, swap it with low and increment both
If mid is 1, increment mid
If mid is 2, swap it with high and decrement high.
**********************************************************************************/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo=0, mid=0, hi=nums.size()-1;
        
        while(mid<=hi) {
            switch(nums[mid]) {
                case 0: 
                    swap(nums[lo], nums[mid]);
                    lo++; mid++;
                    break;
                    
                case 1: 
                    mid++;
                    break;
                    
                case 2: 
                    swap(nums[hi], nums[mid]);
                    hi--;
                    break;
            }
        }
    }
};