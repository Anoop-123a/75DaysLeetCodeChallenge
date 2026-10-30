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

    int solveUsingTab(string &a,string &b,int i,int j){
         int n1=a.length();
        int n2=b.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                
          int ans=0;

          if(a[i]==b[j]){
           
             ans= 1+dp[i+1][j+1];
          }
          else{
            ans= 0+max(dp[i][j+1],dp[i+1][j]);
          }

          dp[i][j]= ans;
            }
        }

        return  dp[0][0]; 

   }
 
   int solveUsingSpace(string &a,string &b){
        int n1=a.length();
        int n2=b.length();
       vector<int>curr(n2+1,0);
       vector<int>next(n2+1,0);


        
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                
          int ans=0;

          if(a[i]==b[j]){
            // dp[i+1] is our next row
             ans= 1+next[j+1];
          }
          else{
            // dp[i] is our curr 
            // dp[i+1] is our next row
            ans= 0+max(curr[j+1],next[j]);
          }

          curr[j]= ans;
            }
            // shift
            next=curr;
        }

        return  next[0]; 

   }
   


    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        int n1=text1.length();
        int n2=text2.length();
        // return solveUsingRec(text1,text2,i,j);
        // vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        // return solveUsingMemo(text1,text2,i,j,dp);
        //  return solveUsingTab(text1,text2,i,j);
          return solveUsingSpace(text1,text2);
         
    } 
};