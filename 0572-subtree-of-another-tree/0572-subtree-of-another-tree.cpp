class Solution {
public:
    // Helper function to check if two trees are identical
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;

        if (a->val != b->val) return false;

        return isSame(a->left, b->left) &&
               isSame(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        // Check if current node matches subRoot
        if (isSame(root, subRoot)) return true;

        // Otherwise check in left or right subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};