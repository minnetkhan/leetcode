// Source : https://leetcode.com/problems/trapping-rain-water/
// Date   : 12-02-2022

/********************************************************************************** 

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

**********************************************************************************/

/**********************************************************************************  

Find the area by cumulative way. 
1. arr[left] or arr[right] always is a pointer to a value which is the max value found so far, 
searching from left and right.

2. If arr[left] <= arr[right], this means that arr[right] is the max value found so far. 
This also means that maxLeft will be less than or equal to arr[right], 
which means that maxLeft will be bounding the addition to the answer(res variable, in this solution), 
since it has be less than or equal to arr[right] e, so we don't have to consider maxRight when adding to the counter.

3. If arr[left] > arr[right], this means at arr[left] is the max value found so far. 
Same thing applies as explained in the paragraph above.

**********************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        
        int leftMax=0, rightMax=0;
        int result=0;
        
        while(left<right) {
            if(height[left]<=height[right]) {
                if(height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    result = result+(leftMax-height[left]);
                }
                left++;
            }
            else {
                if(height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {
                    result = result+(rightMax-height[right]);
                }
                right--;
            }
        }
        
        return result;
    }
};