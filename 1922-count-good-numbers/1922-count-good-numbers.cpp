class Solution {
public:
     long long power(long long a, long long b) {
     long long MOD = 1e9 + 7;
     if(b==0){
        return 1;
     }
     long long half=power(a,b/2);
      long long result=(half*half)%MOD;
     if(b%2==1){
        result=(result*a) %MOD;

     }
     return result;

     }

    int countGoodNumbers(long long n) {
        long long MOD = 1e9 + 7;
        long long odd_postion = n/ 2;
        long long even_postion = (n+1)/ 2;
        int ans=  ((long long)power(5, even_postion) * (long long)power(4, odd_postion)) % MOD;
        return ans ;
    }
};