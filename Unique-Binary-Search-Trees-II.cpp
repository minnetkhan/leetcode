// Source : https://leetcode.com/problems/unique-binary-search-trees-ii/
// Date   : 18-05-2022

/********************************************************************************** 

Given an integer n, return all the structurally unique BST's (binary search trees), 
which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

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
    vector<TreeNode *> generateTreesUtil(int start, int end) {
        if(start > end) {
            return {NULL};
        }
        
        vector<TreeNode *> result;
        
        for(int i=start; i<=end; i++) {
            vector<TreeNode *> leftTrees = generateTreesUtil(start, i-1);
            vector<TreeNode *> rightTrees = generateTreesUtil(i+1, end);
            
            for(auto leftTree: leftTrees) {
                for(auto rightTree: rightTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {    
        return generateTreesUtil(1, n);
    }
};