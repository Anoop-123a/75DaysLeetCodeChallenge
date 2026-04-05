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

    // DFS + Prefix Sum + Backtracking
    void solve(TreeNode* root, long long& currentSum, int targetSum,
               map<long long, int>& mp, int& count) {
        
        // Base case
        if (root == NULL) return;

        // 1. Add current node value to prefix sum
        currentSum += root->val;

        // 2. Check how many previous prefix sums can form target
        //    (currentSum - targetSum) should exist
        count += mp[currentSum - targetSum];

        // 3. Store current prefix sum in map (frequency)
        mp[currentSum]++;

        // 4. Explore left and right subtree
        solve(root->left, currentSum, targetSum, mp, count);
        solve(root->right, currentSum, targetSum, mp, count);

        // 5. Backtrack:
        //    remove current node's contribution before going up
        mp[currentSum]--;           // decrease frequency
        currentSum -= root->val;    // restore previous sum
    }

    int pathSum(TreeNode* root, int targetSum) {
        
        long long currentSum = 0;   // use long long to avoid overflow
        int count = 0;

        // Map stores: prefixSum → frequency
        map<long long, int> mp;

        // Important base case:
        // helps when path itself equals target
        mp[0] = 1;

        // Start DFS
        solve(root, currentSum, targetSum, mp, count);

        return count;
    }
};