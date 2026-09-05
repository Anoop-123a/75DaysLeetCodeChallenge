// Brute force-->>

// class Solution {
// public:
//     int firstStableIndex(vector<int>& nums, int k) {
//         int size=nums.size();
//         for(int i=0;i<size;i++){
//             int maxElement=*max_element(nums.begin(),nums.begin()+i+1);
//             int minElement=*min_element(nums.begin()+i,nums.end());
//             int instabale_score =maxElement-minElement;
//             if(instabale_score<=k){
//                return i;
//             }
        
//         }

//         return -1;
        
//     }
// };

// optimal-->by the help of prefix-->>

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefixMax(n);
        vector<int>prefixMin(n);
        prefixMax[0]=nums[0];
       // Store maximum from 0 to i
        for(int i=1;i<n;i++){
            if( prefixMax[i-1]<nums[i]){
                prefixMax[i]=nums[i];
            }
            else{
                prefixMax[i]=prefixMax[i-1];  
            }
        }

      // Store minimum from i to n-1
        prefixMin[n-1]=nums[n-1];
          for(int i=n-2;i>=0;i--){
            if( prefixMin[i+1]>nums[i]){
                prefixMin[i]=nums[i];
            }
            else{
                prefixMin[i]=prefixMin[i+1];  
            }
        }

  // Find the first stable index-->>
        for(int i=0;i<n;i++){
            if(prefixMax[i]-prefixMin[i]<=k){
                return i;
            }
        }
    


    return -1;


    
        
    }
};