// 75 Leetcode Challenge-->>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, int target, int sum) {
        // Base case-->>
         if (root == NULL) {
            return false;
        }
        // current node tak ka sum-->>
        sum = sum + root->val;

        // if a leaf node then check for target-->>
        if (root->left == NULL && root->right == NULL) {
            if (sum == target) {
                return true;
            }
        
        
         else {
            return false;
        }
        
        }
    
        // baaki recursion sambhalega
        bool leftAns = solve(root->left, target, sum);
        bool rightAns = solve(root->right, target, sum);
        return leftAns || rightAns;
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};