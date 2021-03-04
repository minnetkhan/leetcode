// Source : https://leetcode.com/problems/map-of-highest-peak/
// Date   : 20-02-2021

/********************************************************************************** 

You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. 
A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter 
(i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. 
If there are multiple solutions, return any of them.

nput: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]

**********************************************************************************/

class Solution {
    bool safe(int newX, int newY, int m, int n) {
        return newX >= 0 && newX < m && newY >= 0 && newY < n;
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<pair<int, int>> dirs = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        
        queue<pair<int, int>> q;
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            pair<int, int> topVal = q.front();
            q.pop();
            int x = topVal.first, y = topVal.second;
            visited[x][y] = true;
            for (auto& dir : dirs) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (safe(newX, newY, m, n) && !visited[newX][newY]) {
                    isWater[newX][newY] = isWater[x][y] + 1;
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }   
            }
        }
        
        return isWater;
    }
};