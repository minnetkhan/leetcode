// Source : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Date   : 16-02-2021

/********************************************************************************** 

Return the root node of a binary search tree that matches the given preorder traversal.

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
    TreeNode *constructTree(vector<int> &preorder, int start, int end) {
        if(start > end) {
            return NULL;
        }
        
        int pos;
        for(int i=start; i<=end; i++) {
            if(preorder[i] > preorder[start]) {
                pos = i;
                break;
            }
        }
        
        TreeNode *root = new TreeNode(preorder[start]);
        root->left = constructTree(preorder, start+1, pos-1);
        root->right = constructTree(preorder, pos, end);
        
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructTree(preorder, 0, preorder.size()-1);
    }
};