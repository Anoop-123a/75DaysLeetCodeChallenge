class Solution {
public:
    bool solveUsingRec(vector<int>& nums, int index, int target) {
        // Base case-->>
        if (index >= nums.size()) {
            return false;
        }
        if (target == 0) {
            return true;
        }

        bool includeAns = false;
        if (nums[index] <= target) {
            includeAns = solveUsingRec(nums, index + 1, target - nums[index]);
        }
        bool excludeAns = solveUsingRec(nums, index + 1, target);
        return includeAns || excludeAns;
    }

    bool solveUsingMemo(vector<int>& nums, int index, int target,
                        vector<vector<int>>& dp) {
        // Base case-->>
        if (index >= nums.size()) {
            return false;
        }
        if (target == 0) {
            return true;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        bool includeAns = false;
        if (nums[index] <= target) {
            includeAns =
                solveUsingMemo(nums, index + 1, target - nums[index], dp);
        }
        bool excludeAns = solveUsingMemo(nums, index + 1, target, dp);
        dp[index][target] = includeAns || excludeAns;
        return dp[index][target];
    }

    bool solveUsingTabulation(vector<int>& nums, int target,
                              vector<vector<int>>& dp) {
        for (int i = 0; i < nums.size(); i++)
            dp[i][0] = 1;
        for (int index = nums.size() - 1; index >= 0; index--) {
            for (int t = 1; t <= target; t++) {
                bool include = t - nums[index] >= 0
                                   ? dp[index + 1][t - nums[index]]
                                   : false;
                bool exclude = dp[index + 1][t];
                dp[index][t] = (include || exclude);
            }
        }
        return dp[0][target];
    }

    bool solveUsingSpace(vector<int>& nums, int target) {
        vector<int> curr(target + 1, 0);
        vector<int> prev(target + 1, 0);
        prev[0] = 1;
        curr[0] = 1;
        for (int index = nums.size() - 1; index >= 0; index--) {
            for (int t = 1; t <= target; t++) {
                bool include =
                    t - nums[index] >= 0 ? prev[t - nums[index]] : false;
                bool exclude = prev[t];
                curr[t] = (include || exclude);
            }
            prev = curr;
        }
        return curr[target];
    }

    bool canPartition(vector<int>& nums) {
        int index = 0;
        int sum = 0;
        int n = nums.size();
        for (auto it : nums) {
            sum = sum + it;
        }
        // agar hamara target odd aa jaye toh hame false return kar dena hai
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        // int ans=solveUsingRec(nums,0,target);
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        //  int ans=solveUsingMemo(nums,0,target,dp);
        // int ans=solveUsingTabulation(nums,target,dp);
        int ans = solveUsingSpace(nums, target);

        return ans;
    }
};