// Source : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
// Date   : 04-03-2021

/********************************************************************************** 

Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

**********************************************************************************/

class Solution {
public:
    void traverse(TreeNode *root, TreeNode *parent, TreeNode *grandParent, int &sum) {
        if(!root)
            return ;
        
        if(grandParent && grandParent->val%2 == 0) {
            sum += root->val;
        }
        
        traverse(root->left, root, parent, sum);
        traverse(root->right, root, parent, sum);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)
            return 0;
        
        int sum=0;
        
        traverse(root, NULL, NULL, sum);        
        
        return sum;
    }
};