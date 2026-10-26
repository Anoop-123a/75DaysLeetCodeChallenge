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
    int solveUsingRec(TreeNode* root) {
        // Base case-->>
        if (root == NULL) {
            return 0;
        }

        // Include current node
        int includeAns = root->val;
        if (root->left) {
            includeAns += solveUsingRec(root->left->left);
            includeAns += solveUsingRec(root->left->right);
        }
        if (root->right) {
            includeAns += solveUsingRec(root->right->right);
            includeAns += solveUsingRec(root->right->left);
        }

        int excludeAns = solveUsingRec(root->left) + solveUsingRec(root->right);

        int ans = max(includeAns, excludeAns);
        return ans;
    }
    int solveUsingMemo(TreeNode* root, unordered_map<TreeNode*, int>& map) {
        // Base case-->>
        if (root == NULL) {
            return 0;
        }

        if (map[root] != 0) {
            return map[root];
        }
        // Include current node
        int includeAns = root->val;
        if (root->left) {
            includeAns += solveUsingMemo(root->left->left, map);
            includeAns += solveUsingMemo(root->left->right, map);
        }
        if (root->right) {
            includeAns += solveUsingMemo(root->right->right, map);
            includeAns += solveUsingMemo(root->right->left, map);
        }

        int excludeAns =
            solveUsingMemo(root->left, map) + solveUsingMemo(root->right, map);

        int ans = max(includeAns, excludeAns);
        map[root] = ans;
        return ans;
    }

    int solveUsingTab(TreeNode* root) {

        if(root==NULL)
        {
            return 0;
        }
        unordered_map<TreeNode*, int> map;

        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});
        while (!st.empty()) {
            auto [node, visited] = st.top();
            st.pop();
            if (visited) {
                // Include current node
                int includeAns = node->val;
                if (node->left) {
                    includeAns += map[node->left->left];
                    includeAns += map[node->left->right];
                }
                if (node->right) {
                    includeAns += map[node->right->right];
                    includeAns += map[node->right->left];
                }

                int excludeAns = map[node->left] + map[node->right];

                int ans = max(includeAns, excludeAns);
                map[node] = ans;
            }
            else{
                st.push({node,true});
                if(node->left){
                    st.push({node->left,false});
                }
                if(node->right){
                    st.push({node->right,false});
                }
            }
        }
        return map[root];
    }
    int rob(TreeNode* root) {
        // int ans=solveUsingRec(root);
        // unordered_map<TreeNode*, int> map;
        // int ans = solveUsingMemo(root, map);
        int ans = solveUsingTab(root);
        return ans;
    }
};