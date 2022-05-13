// Source : https://leetcode.com/problems/distribute-coins-in-binary-tree/
// Date   : 14-05-2022

/********************************************************************************** 

You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.
In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.
Return the minimum number of moves required to make every node have exactly one coin.

Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

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
    int preorderTraversal(TreeNode *root, int &result) {
        if(root == NULL) {
            return 0;
        }
        
        int leftCoin = preorderTraversal(root->left, result);
        int rightCoin = preorderTraversal(root->right, result);
        
        result += abs(leftCoin)+abs(rightCoin);
        
        return (root->val+leftCoin+rightCoin)-1;
    }
    
    int distributeCoins(TreeNode* root) {
        int result = 0;
        preorderTraversal(root, result);
        
        return result;
    }
};