class Solution {
public:

   int solveUsingRecursion(vector<int>& arr,int index, int target,int currSum ){
    //    Base case-->>

    if(index==arr.size()){
    if(currSum==target){
        return 1;
    }
    else{
        return 0;
    }
    }

    
  
    int positiveAns=solveUsingRecursion(arr,index+1,target,currSum+arr[index]);
    int negativeAns=solveUsingRecursion(arr,index+1,target,currSum-arr[index]);
    int totalAns=positiveAns+negativeAns;
    return  totalAns;

   }

 int solveUsingMemo(vector<int>& arr, int index, int target,
                   int currSum, vector<vector<int>>& dp, int totalSum) {

    // Base case -->>
    if (index == arr.size()) {
        if (currSum == target) {
            return 1;
        }
        else {
            return 0;
        }
    }

    // Convert currSum into a valid DP index
    // Because currSum can be negative
    int validIndex = currSum + totalSum;

    // If this state is already calculated
    if (dp[index][validIndex] != -1) {
        return dp[index][validIndex];
    }

    // Choose positive sign -->>
    int positiveAns = solveUsingMemo(
        arr, index + 1, target,
        currSum + arr[index], dp, totalSum
    );

    // Choose negative sign -->>
    int negativeAns = solveUsingMemo(
        arr, index + 1, target,
        currSum - arr[index], dp, totalSum
    );

    // Total number of ways -->>
    int totalAns = positiveAns + negativeAns;

    // Store answer for current state -->>
    dp[index][validIndex] = totalAns;

    return totalAns;
}


   int solveUsingTab(vector<int>& arr, int target, int totalSum) {
        int n = arr.size();

        // DP table
        vector<vector<int>> dp(
            n + 1,
            vector<int>(2 * totalSum + 1, 0)
        );

        // Base case
        // All elements are used and currSum == target
        dp[n][target + totalSum] = 1;

        // Fill DP from bottom to top
        for(int index = n - 1; index >= 0; index--) {

            for(int currSum = -totalSum;
                currSum <= totalSum;
                currSum++) {

                int positiveAns = 0;
                int negativeAns = 0;

                // Add current element
                if(currSum + arr[index] <= totalSum) {
                    positiveAns =
                        dp[index + 1]
                          [currSum + arr[index] + totalSum];
                }

                // Subtract current element
                if(currSum - arr[index] >= -totalSum) {
                    negativeAns =
                        dp[index + 1]
                          [currSum - arr[index] + totalSum];
                }

                // Total ways
                dp[index][currSum + totalSum] =
                    positiveAns + negativeAns;
            }
        }

        // Starting state: index = 0, currSum = 0
        return dp[0][totalSum];
    }



int solveUsingOpt(vector<int>& arr, int target, int totalSum){


       int n = arr.size();
       vector<int>curr(2*totalSum+1,0);
       vector<int>prev(2*totalSum+1,0);  
        prev[target + totalSum]=1;       

        for(int index = n - 1; index >= 0; index--) {

             // Reset current row
          fill(curr.begin(), curr.end(), 0);

            for(int currSum = -totalSum;
                currSum <= totalSum;
                currSum++) {

                int positiveAns = 0;
                int negativeAns = 0;

                // Add current element
                if(currSum + arr[index] <= totalSum) {
                    positiveAns =
                        prev[currSum + arr[index] + totalSum];
                }

                // Subtract current element
                if(currSum - arr[index] >= -totalSum) {
                    negativeAns =
                        prev[currSum - arr[index] + totalSum];
                }

                // Total ways
                curr[currSum + totalSum] =
                    positiveAns + negativeAns;
            }

            prev=curr;
        }

        // Starting state: index = 0, currSum = 0
        return prev[totalSum];
}


int findTargetSumWays(vector<int>& nums, int target) {

    int n = nums.size();
    int index = 0;
    int currSum = 0;
//   int  ans=solveUsingRecursion(nums,index,target,currSum);
    // Calculate maximum possible sum -->>
    int totalSum = 0;

    for (int x : nums) {
        totalSum += x;
    }

    // If target is outside possible range -->>
    if (abs(target) > totalSum) {
        return 0;
    }

    // DP size:
    // currSum can range from -totalSum to +totalSum
    // vector<vector<int>> dp(n,vector<int>(2 * totalSum + 1, -1));
    // int ans = solveUsingMemo(nums, index, target, currSum, dp, totalSum);
    // int ans = solveUsingTab(nums,target,totalSum);
     int ans = solveUsingOpt(nums,target,totalSum);
    
    return ans;
}
};