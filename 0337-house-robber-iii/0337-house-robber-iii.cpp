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
    int solveUsingRec(TreeNode* root){
        // Base case-->>
        if(root==NULL){
            return 0;
        }

         // Include current node
        int includeAns = root->val;
         if(root->left){
         includeAns+=solveUsingRec(root->left->left);
         includeAns+=solveUsingRec(root->left->right);
         }
         if(root->right){
           includeAns+=solveUsingRec(root->right->right);
           includeAns+=solveUsingRec(root->right->left);
         }

        int excludeAns=solveUsingRec(root->left)+solveUsingRec(root->right);

        int ans=max(includeAns,excludeAns);
        return ans;
           
    }
    int solveUsingMemo(TreeNode* root,unordered_map<TreeNode*,int>&map){
        // Base case-->>
        if(root==NULL){
            return 0;
        }

        if(map[root]!=0){
            return map[root];
        }
         // Include current node
        int includeAns = root->val;
         if(root->left){
         includeAns+=solveUsingMemo(root->left->left,map);
         includeAns+=solveUsingMemo(root->left->right,map);
         }
         if(root->right){
           includeAns+=solveUsingMemo(root->right->right,map);
           includeAns+=solveUsingMemo(root->right->left,map);
         }

        int excludeAns=solveUsingMemo(root->left,map)+solveUsingMemo(root->right,map);

        int ans=max(includeAns,excludeAns);
        map[root]=ans;
        return ans;
           
    }
    int rob(TreeNode* root) {
        // int ans=solveUsingRec(root);
       unordered_map<TreeNode*,int>map;
       int ans=solveUsingMemo(root,map);
        return ans;
        
    }
};