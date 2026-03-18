// By division operation-->>
// Better Solution-->>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n=nums.size();
         int total=1;
         int count=0;
         vector<int>ans;
         bool track=false;
         for(int i=0;i<n;i++){
            if(nums[i]!=0){
                 total=total*nums[i];
                 
            }
            else{
                count=count+1;
                continue;
            }
         }

         for(int i=0;i<n;i++){
        // Case-1-->>
            if(count ==1){
                if(nums[i]!=0){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(total);
                }
            }
        // Case-2-->>
            else if(count>=2){
                ans.push_back(0);
            }
        // case-3-->>No zero in array
            else{
               ans.push_back(total/nums[i]);
            }
         }

         return ans;

        
    }
};

// Optimal  Solution-->>
