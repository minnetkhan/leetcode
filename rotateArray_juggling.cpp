// Source : https://leetcode.com/problems/rotate-array/
// Date   : 28-02-2021

/********************************************************************************** 

Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Method: A Juggling Algorithm

**********************************************************************************/

class Solution {
private:
    int gcd(int a, int b) {
        if(b==0)
            return a;

        return gcd(b, a%b);
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        int g_c_d = gcd(k, n);

        for(int i=0; i<g_c_d; i++) {
            int j=i;
            int val = nums[j];

            while(true) {
                int jump = j+k;

                if(jump >= n) {
                    jump = jump%n;
                }

                if(jump == i) {
                    nums[jump] = val;
                    break;
                }

                int temp = nums[jump];
                nums[jump] = val;
                val = temp;

                j = jump;
            }
        }
    }
};