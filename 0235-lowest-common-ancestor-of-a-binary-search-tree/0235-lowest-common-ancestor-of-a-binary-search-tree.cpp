// Method-->>
// Solving By Binary search concept-->>


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

        // case-1-->> p and q are both on left side
        if(p->val<root->val && q->val<root->val){
            TreeNode* leftAns=lowestCommonAncestor(root->left, p, q);
            if(leftAns!=NULL){
                return leftAns;
            }
        }
        // case-2-->>p and q are both on right side  
        if(p->val>root->val && q->val>root->val){
            TreeNode* rightAns=lowestCommonAncestor(root->right, p, q);
            if(rightAns!=NULL){
                return rightAns;
            }
        }
        // case-3-->p is on left and q is on right
        // return root;
        // case-4-->>p is on right and q is on left
        return root;
        
    }
};