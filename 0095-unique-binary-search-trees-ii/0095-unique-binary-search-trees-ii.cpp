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
    vector<TreeNode*> solveUsingRec(int start, int end) {
        // Base case-->>
        if (start > end) {
            return {NULL};
        }
        if(start==end){
            return {new TreeNode(start)};
        }
        vector<TreeNode*>ans;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = solveUsingRec(start, i - 1);
            vector<TreeNode*> right = solveUsingRec(i + 1, end);

            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    // create a node-->>
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];

                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        int start = 1;
        int end = n;
        vector<TreeNode*> ans = solveUsingRec(start, end);
        return ans;
    }
};