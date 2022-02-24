// Source : https://leetcode.com/problems/spiral-matrix/
// Date   : 25-02-2021

/********************************************************************************** 

Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

**********************************************************************************/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowBegin=0, rowEnd=matrix.size()-1, colBegin=0, colEnd=matrix[0].size()-1;
        vector<int> result;
        
        while(rowBegin<=rowEnd && colBegin<=colEnd) {

            for(int j=colBegin; j<=colEnd; j++) {
                result.push_back(matrix[rowBegin][j]);
            }
            
            rowBegin++;
            
            for(int i=rowBegin; i<=rowEnd; i++) {
                result.push_back(matrix[i][colEnd]);
            }
            
            colEnd--;
            
            if(rowBegin <= rowEnd)
                for(int j=colEnd; j>=colBegin; j--) {
                    result.push_back(matrix[rowEnd][j]);
                }
            
            rowEnd--;
            
            if(colBegin <= colEnd)
                for(int i=rowEnd; i>=rowBegin; i--) {
                    result.push_back(matrix[i][colBegin]);
                }
            
            colBegin++;
        }
        
        return result;
    }
};