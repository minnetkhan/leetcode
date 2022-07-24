// Source : https://leetcode.com/problems/recover-binary-search-tree/
// Date   : 24-07-2022

/********************************************************************************** 

You are given the root of a binary search tree (BST), 
where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.

Intuition:
We need to find the first and second elements that are not in order right?

How do we find these two elements? For example, we have the following tree that is printed as in order traversal:

6, 3, 4, 5, 2

We compare each node with its next one and 
we can find out that 6 is the first element to swap because 6 > 3 
and 2 is the second element to swap because 2 < 5.

Really, what we are comparing is the current node and its previous node in the "in order traversal".

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
    void recoverUtil(TreeNode *root, TreeNode *&node1, TreeNode *&node2, TreeNode *&prev) {
        if(root == NULL) {
            return ;
        }
        
        recoverUtil(root->left, node1, node2, prev);
        
        if(node1 == NULL && prev != NULL && prev->val >= root->val) 
            node1 = prev;
        if(node1 != NULL && prev->val >= root->val) 
            node2 = root;
        
        prev = root;
        
        recoverUtil(root->right, node1, node2, prev);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *node1 = NULL, *node2 = NULL, *prev = NULL;
        
        recoverUtil(root, node1, node2, prev);
        
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
};