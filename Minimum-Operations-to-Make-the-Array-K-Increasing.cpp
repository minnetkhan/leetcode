// Source : https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/
// Date   : 18-05-2022

/********************************************************************************** 

You are given a 0-indexed array arr consisting of n positive integers, and a positive integer k.

The array arr is called K-increasing if arr[i-k] <= arr[i] holds for every index i, where k <= i <= n-1.

For example, arr = [4, 1, 5, 2, 6, 2] is K-increasing for k = 2 because:
arr[0] <= arr[2] (4 <= 5)
arr[1] <= arr[3] (1 <= 2)
arr[2] <= arr[4] (5 <= 6)
arr[3] <= arr[5] (2 <= 2)
However, the same arr is not K-increasing for k = 1 (because arr[0] > arr[1]) or k = 3 (because arr[0] > arr[3]).
In one operation, you can choose an index i and change arr[i] into any positive integer.

Return the minimum number of operations required to make the array K-increasing for the given k.


Intuition:
Find the length of longest increasing subsequence. 
Then only remaining number needs to be changed.

**********************************************************************************/

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int result = 0;
        
        for(int i=0; i<k; i++) {
            vector<int> monoStack;
            
            for(int j=i; j<n; j+=k) {
                if(monoStack.size() == 0 || monoStack.back() <= arr[j]) {
                    monoStack.push_back(arr[j]);
                }
                else {
                    auto itr = upper_bound(monoStack.begin(), monoStack.end(), arr[j]);
                    *itr = arr[j];
                }
            }
            
            result += monoStack.size();
        }
        
        return n-result;
    }
};