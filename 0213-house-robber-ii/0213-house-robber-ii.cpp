class Solution {
public:
    int solveUsingRec(vector<int>& nums, int start, int end) {
        //  base case-->>
        if (start > end) {
            return 0;
        }

        //  include-->>
        int includeAns = nums[start] + solveUsingRec(nums, start + 2, end);

        // exclude->>
        int excludeAns = 0 + solveUsingRec(nums, start + 1, end);
        int finalAns = max(includeAns, excludeAns);
        return finalAns;
    }
    int solveUsingMemo(vector<int>& nums, int start, int end, vector<int>& dp) {
        //  base case-->>
        if (start > end) {
            return 0;
        }

        // step-3-->>
        if (dp[start] != -1) {
            return dp[start];
        }

        //  include-->>
        int includeAns = nums[start] + solveUsingMemo(nums, start + 2, end, dp);

        // exclude->>
        int excludeAns = 0 + solveUsingMemo(nums, start + 1, end, dp);
        int finalAns = max(includeAns, excludeAns);

        // step -2-->>
        // ans store in dp array -->>
        dp[start] = finalAns;
        return finalAns;
    }

    
    int solveUsingTab(vector<int>& nums,int start,int end) {
        // step-1-->>
        // dp array create initialise
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        // step-3-->> reverse the flow loop,copy paste

        for (int i = end; i >=start; i--) {
            int temp = 0;
            if (i + 2 <= end) {
                temp = dp[i + 2];
            }

            //  include-->>
            int includeAns = nums[i] + temp;
            // exclude->>
            int excludeAns = 0 + dp[i + 1];
            dp[i] = max(includeAns, excludeAns);
        }

        return dp[start];
    }

    int rob(vector<int>& nums) {
        // Implement your solution logic here
        int n = nums.size();
        int index = 0;
        if (n == 1) {
            return nums[0];
        }
        //  int case1= solveUsingRec(nums,0,n-2);
        //  int case2=  solveUsingRec(nums,1,n-1);
        // vector<int> dp1(nums.size() + 1, -1);
        // int case1 = solveUsingMemo(nums, 0, n - 2, dp1);
        //  vector<int> dp2(nums.size() + 1, -1);
        // int case2 = solveUsingMemo(nums, 1, n - 1, dp2);
          int case1= solveUsingTab(nums,0,n-2);
         int case2=  solveUsingTab(nums,1,n-1);
        // int ans=solveUsingSpace(nums);
        return max(case1, case2);
    }
};