// 75 Leetcode challenge-->>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base case
        if (root == NULL) return NULL;
        
        // If current node is p or q
        if (root == p || root == q) return root;
        
        // Search in left and right
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        
        // If both sides returned non-null → LCA found
        if (leftAns != NULL && rightAns != NULL)
            return root;
        
        // Otherwise return the non-null side
        if (leftAns != NULL) return leftAns;
        else return rightAns;
    }
};