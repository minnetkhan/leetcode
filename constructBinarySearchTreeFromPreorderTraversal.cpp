// Source : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Date   : 16-02-2021

/********************************************************************************** 

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, 
any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  
Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

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
private:
    TreeNode *util(vector<int> &preorder, int start, int end) {
        if(start > end) {
            return NULL;
        }
        
        int pos = INT_MAX;
        for(int i=start; i<=end; i++) {
            if(preorder[start] < preorder[i]) {
                pos = i;
                break;
            }
        }
        
        TreeNode *root = new TreeNode(preorder[start]);
        
        if(pos != INT_MAX) {
            /*
                all number smaller than root will be on left
                & greater than root will be on right.
            */
            root->left = util(preorder, start+1, pos-1);
            root->right = util(preorder, pos, end);
        }
        else {
            /* 
                for left skewed trees
                [3,2,1]
            */
            root->left = util(preorder, start+1, end);
        }
        
        return root;
    }
    
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return util(preorder, 0, preorder.size()-1);
    }
};