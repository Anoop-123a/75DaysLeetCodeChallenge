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

    TreeNode* solve(TreeNode* root1,TreeNode*root2){
        int sum1=0;
        int sum2=0;
        if(root1!=NULL){
            sum1=root1->val;
        }
        if(root2!=NULL){
            sum2=root2->val;
            
        }
        if(root1==NULL &&root2==NULL){
            return NULL;
        }
       TreeNode* newRoot=new TreeNode(sum1+sum2);
       
        newRoot->left=solve(root1?root1->left:NULL,root2?root2->left:NULL);
        
        newRoot->right=solve(root1?root1->right:NULL,root2?root2->right:NULL);
    
        return newRoot ;

    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* newRoot=solve(root1,root2);
        return newRoot;

        
    }
};