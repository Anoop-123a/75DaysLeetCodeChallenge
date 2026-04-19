// 75 Leetcode challenge-->>


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

   int maxDepth(TreeNode* root) {
        // base case-->>
        if(root==NULL){
            return 0 ;
        }

        int leftHeight=maxDepth(root->left)+1;
        int rightHeight=maxDepth(root->right)+1;

        return max(leftHeight,rightHeight);

        
    }

    int diameterOfBinaryTree(TreeNode* root) {
    //   Base case-->>
    if(root==NULL){
        return 0;
    }

    // LST+ROOT+RST-->>
    int option1=maxDepth(root->left) + maxDepth(root->right);
   int option2  =diameterOfBinaryTree(root->left);
   int option3=diameterOfBinaryTree(root->right);
   int ans=max(option1 ,max(option2,option3));
   return ans;
        
    }
};


// It is not best complexity b/c its complexity is exponential