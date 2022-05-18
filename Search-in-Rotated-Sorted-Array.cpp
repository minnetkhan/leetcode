// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Date   : 18-05-2022

/********************************************************************************** 

Search in Rotated Sorted Array

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

**********************************************************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(nums[mid] > nums[hi]) lo=mid+1;
            else hi=mid;
        }
        
        int pivot = lo;
        lo=0; hi=nums.size()-1;
        
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            int realMid = (mid+pivot)%nums.size();
            
            if(target == nums[realMid]) {
                return realMid;
            }
            else if(target > nums[realMid]) {
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        
        return -1;
    }
};