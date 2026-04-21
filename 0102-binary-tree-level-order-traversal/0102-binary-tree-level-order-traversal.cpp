// 75 Leetcode challenge-->>

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
    void solve(TreeNode* root, vector<vector<int>>& ans, vector<int>& temp,
               queue<TreeNode*> q) {
        if (root == NULL) {
            return;
        }
        // Intial pushing -->>
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {

            TreeNode* front = q.front();
            q.pop();
            if (front == NULL) {
                // iska matlab hai ki ham ek level traverse kar chuke hai aur
                // dusara level ki sare value queue ke andar push chuke hai
                ans.push_back(temp);
                temp.clear();
                if (!q.empty()) {
                    q.push(NULL);
// Ek baar null dalne ke baad ham yaha se NULL queue ke andar push kar rahe hai
                }

            }

            else {
                temp.push_back(front->val);
                if (front->left != NULL) {
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    q.push(front->right);
                }
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> q;
        solve(root, ans, temp, q);
        return ans;
    }
};