// It gives TLE-->>
// class Solution {
// public:
//     int minMoves(vector<int>& nums) {
//         int n=nums.size();
//         int i=n-1;
//         int count=0;
//         while(i>0){
//             if(nums[i]==nums[i-1]){
//                i--;
//             }
//             else if(nums[i]>nums[i-1]){
//                 nums[i]=nums[i]-1;
//                 i=n-1;
//                 count++;
//             }

//         }

//         return count;
        
//     }
// };

class Solution {
public:
    int minMoves(vector<int>& nums) {
       int n=nums.size();
       int count=0;
       int minElement=*min_element(nums.begin(),nums.end());

       for(int i=0;i<n;i++){  
          count=count+(nums[i]-minElement);
       }
       return count;
    }
};