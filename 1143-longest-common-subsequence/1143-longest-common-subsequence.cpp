class Solution {
public:
   int solveUsingRec(string a,string b,int i,int j){
          
          if(i==a.length()){
            return 0;
          }
          if(j==b.length()){
            return 0;
          }

          int ans=0;

          if(a[i]==b[j]){
             ans= 1+solveUsingRec(a,b,i+1,j+1);
          }
          else{
            ans= 0+max(solveUsingRec(a,b,i,j+1),solveUsingRec(a,b,i+1,j));
          }

          return ans;

   }

    int solveUsingMemo(string &a,string &b,int i,int j, vector<vector<int>>&dp){
          
          if(i==a.length()){
            return 0;
          }
          if(j==b.length()){
            return 0;
          }
          if(dp[i][j]!=-1){
            return dp[i][j];
          }

          int ans=0;

          if(a[i]==b[j]){
           
             ans= 1+solveUsingMemo(a,b,i+1,j+1,dp);
          }
          else{
            ans= 0+max(solveUsingMemo(a,b,i,j+1,dp),solveUsingMemo(a,b,i+1,j,dp));
          }

          dp[i][j]= ans;
          return dp[i][j];

   }


    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        int n1=text1.length();
        int n2=text2.length();
        // return solveUsingRec(text1,text2,i,j);
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solveUsingMemo(text1,text2,i,j,dp);
    } 
};