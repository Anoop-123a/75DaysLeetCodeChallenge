class Solution {
public:
     int solveUsingRec(vector<int>& piles,int start,int M){
        // Base case-->>

        if(start>=piles.size()){
            return 0;
        }

        int total=0;
        int ans=0;
     
        for(int X=1;X<=2*M && start+X<=piles.size();X++){
            total=total+piles[start+X-1];
             int newM = max(M, X);

            //  jiska turn hai uska maximum score dega opponent-->>
            int opponent=solveUsingRec(piles,start+X,newM);
              int remaining = 0;
            for (int i = start + X; i < piles.size(); i++) {
                remaining += piles[i];
            }
            int current=total+(remaining-opponent);

           ans= max(ans,current);
            
        }

        return ans;

   }

       int solveUsingMemo(vector<int>& piles,int start,int M,vector<vector<int>>&dp){
        // Base case-->>

        if(start>=piles.size()){
            return 0;
        }

        int total=0;
        int ans=0;

        if(dp[start][M]!=-1){
            return dp[start][M];
        }
     
        for(int X=1;X<=2*M && start+X<=piles.size();X++){
            total=total+piles[start+X-1];
             int newM = max(M, X);
            int opponent=solveUsingMemo(piles,start+X,newM,dp);
              int remaining = 0;
            for (int i = start + X; i < piles.size(); i++) {
                remaining += piles[i];
            }
            int current=total+(remaining-opponent);

           ans= max(ans,current);
            
        }
        dp[start][M]=ans;
        return ans;

   }


    int stoneGameII(vector<int>& piles) {
        int M=1;
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans=solveUsingRec(piles,0,M);
         int ans=solveUsingMemo(piles,0,M,dp);
        return ans;
        
      
    }
};