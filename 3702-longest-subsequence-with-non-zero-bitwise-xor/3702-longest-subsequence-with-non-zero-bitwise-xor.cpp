class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

       int total_xor=0;
       long long  total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_xor=total_xor^nums[i];
            total_sum=total_sum+nums[i];
        }
        if(nums.size()==0 || total_sum==0){
            return 0;
        }
        else if(total_xor==0){
             return nums.size()-1;
        }
        else{
            return nums.size();

        }


    }
};