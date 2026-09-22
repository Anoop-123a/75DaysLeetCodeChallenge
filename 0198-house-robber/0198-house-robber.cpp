

class Solution {
public:
    // //   1D DP-->>
    // // Rec + Memoisation ->Top down Solution-->
    //   int solveUsingMem(vector<int>&nums,int index,vector<int>&dp){
    //     //  base case-->>
    //      if (index>=nums.size()){
    //         return 0;
    //      }

    //     // step-3-->>
    //      if(dp[index]!=-1){
    //         return dp[index];
    //      }

    //     //  include-->>
    //     int includeAns=nums[index]+solveUsingMem(nums,index+2,dp);

    //     // exclude->>
    //     int excludeAns=0+solveUsingMem(nums,index+1,dp);
    //     int finalAns=max(includeAns,excludeAns);

    //     // step -2-->>
    //     // ans store in dp array -->>
    //     dp[index]=finalAns;
    //     return finalAns;

    //   }

    // Tabulation-->>
    // bottom-up Approach-->>

    int solveUsingTab(vector<int>& nums) {
        // step-1-->>
        // dp array create initialise
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        // step-2-->>
        // analyse base case and fillup dp array-->>
        dp[n] = 0;

        // step-2-->> reverse the flow ,loop,copy paste

        for (int i = n - 1; i >= 0; i--) {
            int temp = 0;
            if (i + 2 <= n) {
                temp = dp[i + 2];
            }

            //  include-->>
            int includeAns = nums[i] + temp;
            // exclude->>
            int excludeAns = 0 + dp[i + 1];
            dp[i] = max(includeAns, excludeAns);
        }

        return dp[0];
    }

    int rob(vector<int>& nums) {
        // Implement your solution logic here
        int index = 0;
        // vector<int>dp(nums.size()+1,-1);
        // int ans= solveUsingMem(nums,index,dp);
        int ans = solveUsingTab(nums);
        return ans;
    }
};
