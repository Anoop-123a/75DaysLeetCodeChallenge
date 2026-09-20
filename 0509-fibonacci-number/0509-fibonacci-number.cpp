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

// using Dp-->>
class Solution {
public:


int fibUsingMemo(int n, vector<int>&dp){
    // base case
    if(n==0 || n==1){
        return {n};
    } 
    // step-3-->>
    // check if the ans is already calculated or not
    if(dp[n]!=-1){
        return dp[n]; //agar yaha pe -1 nahi hai to iska matlab hai ki isko pehle se hi calculate kar chuka hu
    }

    int ans=fibUsingMemo(n-1,dp)+fibUsingMemo(n-2,dp);
    // step-2-->>
    // store the ans in the dp array
    dp[n]=ans;
    return dp[n];


}



    int fib(int n) {
     vector<int>dp(n+1,-1);
     int ans=fibUsingMemo(n,dp);
     return ans;

    }
};