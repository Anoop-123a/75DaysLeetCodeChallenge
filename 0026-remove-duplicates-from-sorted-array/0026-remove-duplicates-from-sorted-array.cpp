// 75DayLeetCodeChallenge-->>


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        int insertindex=1;
      //New index for unique element in nums.
        for(int i= 1;i<n;i++)
        {
        if(nums[i-1]!=nums[i])
        {
           nums[insertindex]=nums[i]; //value place 
           insertindex++;
        }
        }

       return insertindex; 
    }
};