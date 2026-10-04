class Solution {
public:
     int solveUsingRec(int n, int count) {

        // Base case
        if (count == n) {
            return 1;
        }

        // Overshoot
        if (count > n) {
            return 0;
        }

        int oneAns = solveUsingRec(n, count + 1);
        int twoAns = solveUsingRec(n, count + 2);
        int finalAns=oneAns+twoAns;

        return  finalAns;
     }


   int solveUsingMemo(int n,int count,vector<int>&dp){
    // base case-->>
 
        // Base case
        if (count == n) {
            return 1;
        }

        // Overshoot
        if (count > n) {
            return 0;
        }

        if(dp[count]!=-1){
            return dp[count];
        }

        int oneAns = solveUsingMemo(n, count + 1,dp);
        int twoAns = solveUsingMemo(n, count + 2,dp);
        int finalAns=oneAns+twoAns;
        dp[count]=finalAns;
        return  finalAns;
   }

    int climbStairs(int n) {
        // int ans=solveUsingRec(n,0);
        vector<int>dp(n+1,-1);
        int ans=solveUsingMemo(n,0,dp);
        return ans;
    }
};