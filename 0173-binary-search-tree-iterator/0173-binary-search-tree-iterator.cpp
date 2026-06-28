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

//  Using the array-->>But it take o(n) space
// class BSTIterator {
// public:
//     TreeNode* curr;
//     vector<int>ans;
//     int i=0;
//     BSTIterator(TreeNode* root) {
//        solve(root,ans);
//     }
//      void solve(TreeNode* root,vector<int>&ans){
//         if(root==NULL){
//             return ;
//         }
//         solve(root->left,ans);
//         ans.push_back(root->val);
//         solve(root->right,ans);

//     }
//     int next() {
//         return ans[i++];
        
  
        
//     }
    
//     bool hasNext() {
//        if(i<ans.size()){
//         return true;
//        }
//        else{
//         return false;
//        }
        
//     }
// };

class BSTIterator {
public:
     stack<TreeNode*>s;
     void push_left(TreeNode* root,stack<TreeNode*>&s){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
     }
 
    BSTIterator(TreeNode* root) {
         push_left(root,s);
    }
     
    int next() {
        TreeNode* ans=s.top();
        s.pop();
        if(ans->right!=NULL){
            push_left(ans->right,s);
        }
        return ans->val;   
    }
    
    bool hasNext() {
        if(!s.empty()){
            return true;
        }
      return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */