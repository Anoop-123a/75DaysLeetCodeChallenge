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
     void solve(TreeNode* root,long long  &currentSum, int targetSum,map<long long ,int>&mp,int &count){
       if(root==NULL){
            return ;
        }
      
       currentSum=currentSum+root->val;
         count=count+mp[currentSum-targetSum];
         mp[currentSum]++;
        solve(root->left,currentSum,targetSum,mp,count);
        solve(root->right,currentSum,targetSum,mp,count);
        mp[currentSum]--;
        currentSum=currentSum-root->val;


     }
    int pathSum(TreeNode* root, int targetSum) {
        long long currentSum =0;
        int count=0;
        map<long long ,int>mp;
        mp[0]=1;
        solve(root,currentSum,targetSum,mp,count);
        return count;
        
    }
};