// 75 leetcode challenge-->>

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
    bool solve(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;

        // Check current node
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Left subtree → max becomes root->val
        // Right subtree → min becomes root->val
        return solve(root->left, minVal, root->val) &&
               solve(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};