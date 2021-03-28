// Source : https://leetcode.com/problems/all-possible-full-binary-trees/
// Date   : 28-03-2021

/********************************************************************************** 

Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

**********************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map< int, vector<TreeNode*> > memo;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode *> result;
        
        if(n == 1) {
            return {new TreeNode(0)};
        }
        
        if(memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        
        for(int i=1; i<n; i += 2) {
            /* 
                Creating all possible left and right trees.
                If left tree has 1 node and root has 1 node then right tree will have n-2 roots.
                If left tree have 2 nodes and root has 1 node then right tree will have n-3 roots.
                ...
                If left tree has n-2 nodes and root has 1 node then right tree will have 1 root.
            */
            vector<TreeNode *> leftTree = allPossibleFBT(i);

            vector<TreeNode *> rightTree = allPossibleFBT(n-i-1);
            
            /*
                If left has L trees and right has R trees then total trees will be L*R.
            */
            for(auto left: leftTree) {
                for(auto right: rightTree) {
                    TreeNode *root = new TreeNode(0, left, right);
                    result.push_back(root);
                }
            }
        }
        
        return memo[n] = result;
    }
};