class Solution {
public:
       int solveUsingRec(vector<int>& stoneValue,int start){
        // Base case-->>

        if(start>=stoneValue.size()){
            return 0;
        }

        int total=0;
        int ans = INT_MIN;
     
        for(int X=1;X<=3 && start+X<=stoneValue.size();X++){
            total=total+stoneValue[start+X-1];
            //  jiska turn hai uska maximum score dega opponent-->>
            int opponent=solveUsingRec(stoneValue,start+X);
              int remaining = 0;
            for (int i = start + X; i < stoneValue.size(); i++) {
                remaining += stoneValue[i];
            }
            int current=total+(remaining-opponent);
           ans= max(ans,current);
            
        }

        return ans;

   }

     int solveUsingMemo(vector<int>& stoneValue,int start,vector<int>&dp,vector<int>&suffix){
        // Base case-->>

        if(start>=stoneValue.size()){
            return 0;
        }

        int total=0;
        int ans=INT_MIN;

        if(dp[start]!=INT_MIN){
            return dp[start];
        }
     
        for(int X=1;X<=3 && start+X<=stoneValue.size();X++){
            total=total+stoneValue[start+X-1];
            int opponent=solveUsingMemo(stoneValue,start+X,dp,suffix);
            int remaining = suffix[start + X];//we use this to improve the time complexity
            int current=total+(remaining-opponent);

           ans= max(ans,current);
            
        }
        dp[start]=ans;
        return ans;

   }

   int solveUsingBottomUp(vector<int>& stoneValue,vector<int>&suffix) {

        int n = stoneValue.size();

        // dp[i] = maximum score current player can get
        // from index i
        vector<int> dp(n + 1, 0);

        for (int start = n - 1; start >= 0; start--) {

            int total = 0;
            int ans = INT_MIN;

            for (int X = 1;
                 X <= 3 && start + X <= n;
                 X++) {

                total += stoneValue[start + X - 1];

                int opponent = dp[start + X];

                int remaining = suffix[start + X];

                int current = total + (remaining - opponent);

                ans = max(ans, current);
            }

            dp[start] = ans;
        }

        return dp[0];
    }


    string stoneGameIII(vector<int>& stoneValue) {
       int n=stoneValue.size();
       int total=0;
       for(auto it:stoneValue){
            total+=it;
       }
        // suffix[i] = sum of stoneValue[i ... n-1]
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = stoneValue[i] + suffix[i + 1];
        }
        // int Alice=solveUsingRec(stoneValue,0);
        // vector<int>dp(n+1,INT_MIN);
        // int Alice=solveUsingMemo(stoneValue,0,dp,suffix);
        int Alice=solveUsingBottomUp(stoneValue,suffix);
        int Bob=total-Alice;
        if(Alice>Bob){
            return "Alice";
        }
        else if(Alice<Bob){
            return "Bob";
        }
        else{
           return  "Tie";
        }
    }
};