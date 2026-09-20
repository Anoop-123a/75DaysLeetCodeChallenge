// using recursion-->>

// class Solution {
// public:
//     int fib(int n) {
//            // Base cases
//     if (n == 0) return 0;
//     if (n == 1) return 1;

//     // Recursive relation
//     return fib(n - 1) + fib(n - 2);
//     }
// };

//Method 1:
// using Top-down Dp-->> time->o(n) ans space ->o(1)
class Solution {
public:
    // int fibUsingMemo(int n, vector<int>&dp){
    //     // base case
    //     if(n==0 || n==1){
    //         return {n};
    //     }
    //     // step-3-->>
    //     // check if the ans is already calculated or not
    //     if(dp[n]!=-1){
    //         return dp[n]; //agar yaha pe -1 nahi hai to iska matlab hai ki
    //         isko pehle se hi calculate kar chuka hu
    //     }

    //     int ans=fibUsingMemo(n-1,dp)+fibUsingMemo(n-2,dp);
    //     // step-2-->>
    //     // store the ans in the dp array
    //     dp[n]=ans;
    //     return dp[n];

    // }


//Method 2:
    // using bottom-down Dp-->>time ->O(n) and space-> O(1)
    int fibUsingBottom(int n) {

        //    step-1-->>
        // create dp array-->>
        vector<int> dp(n + 1, -1);
        // step-2-->>
        // analyse base case and fill up dp array
        if(n==0)
        {
            return 0;
        }
        if(n==1){
            return 1;   
        }
        dp[0] = 0;
        dp[1] = 1;

        // step-3-->>
        // reverse the loop wala logic or reverse the top-down flow

        for (int i = 2; i <= n; i++) {
            // copy paste-->>
            int ans = dp[i - 1] + dp[i - 2];
            dp[i] = ans;
        }

        return dp[n];
    }


 //Method 3:
//  space optimisation-->>
  int optimisation(int n) {

        if(n==0)
        {
            return 0;
        }
        if(n==1){
            return 1;   
        }
      int prev1=0;
      int prev2=1;
      int curr=-1;

        for (int i = 2; i <= n; i++) {
           curr=prev1+prev2;
        //    yeh mein pakka bhul jaunga-->>
        prev1=prev2;
        prev2=curr;
        }

        return curr;
    }





    int fib(int n) {
        vector<int> dp(n + 1, -1);
        //  int ans=fibUsingBottom(n,dp);
        // int ans = fibUsingBottom(n);
        int ans=optimisation(n);
        return ans;
    }
};