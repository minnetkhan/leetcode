// Source : https://leetcode.com/problems/number-of-islands/
// Date   : 18-02-2021

/********************************************************************************** 

Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

**********************************************************************************/

class Solution {
public:    
    void markIslands(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '*';
        
        if(i-1>=0 && grid[i-1][j] == '1') {
            markIslands(grid, i-1, j);
        }
        
        if(i+1<grid.size() && grid[i+1][j] == '1') {
            markIslands(grid, i+1, j);
        }
        
        if(j-1>=0 && grid[i][j-1] == '1') {
            markIslands(grid, i, j-1);
        }
        
        if(j+1<grid[i].size() && grid[i][j+1] == '1') {
            markIslands(grid, i, j+1);
        }
    }
    
    int countIslands(vector<vector<char>> &grid) {
        int islands=0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    markIslands(grid, i, j);
                    islands++;
                }
            }
        }
        
        return islands;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        return countIslands(grid);
    }
};