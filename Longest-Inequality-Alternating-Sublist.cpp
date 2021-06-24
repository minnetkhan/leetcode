// Source : https://binarysearch.com/problems/Longest-Inequality-Alternating-Sublist
// Date   : 24-06-2021

/********************************************************************************** 

Given a list of integers nums, return the length of the longest sublist in nums 
such that the equality relation between every consecutive numbers alternates between < and >. 
The first two numbers' inequality may be either < or >

Input: [0, 1, 5, 3, 4]
Output: 4

**********************************************************************************/

/**********************************************************************************  

We iterate over the input pairwise and record the length of the current alternating sublist run and also the maximum length.

Thereby we have to consider three cases:

1. Both numbers are equal:  
    we reset the current length to 1 and continue our run starting at the second number
2. Both numbers are not equal, but the equality did not alternate:
    we reset the length to 2 and continue our run starting at the first number
3. Both numbers are not equal and the equality did alternate:
    we increase the current length by 1

**********************************************************************************/

int giveSign(int a, int b) {
    return a == b ? 0 : a > b ? -1 : 1;
}

int solve(vector<int>& nums) {
    if(nums.size() <= 1) {
        return nums.size();
    }

    int currLen = 1, maxLen = 1, lastSign = 0;

   for(int i=0; i<nums.size()-1; i++) {
       int currSign = giveSign(nums[i], nums[i+1]);
    //    cout<<currSign<<" "<<lastSign<<" "<<currLen<<" "<<maxLen<<endl;
       if(currSign == 0) {
           currLen = 1;
       }
       else if(lastSign == currSign) {
           currLen = 2;
       }
       else {
           currLen += 1;
       }

       lastSign = currSign;
       maxLen = max(currLen, maxLen);
    }

    return maxLen;
}