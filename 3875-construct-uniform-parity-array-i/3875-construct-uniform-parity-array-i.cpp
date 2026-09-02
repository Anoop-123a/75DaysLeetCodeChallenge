// done by me but not optimal in simplicity-->>

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool isOdd=false;
        bool ans=false;
        for(int i=0;i<nums1.size();i++){
            int element=nums1[i];
            if(element%2!=0){
               ans=true; 
               isOdd=true;
            }
            else{
               if(isOdd){
                ans=true;
               }
               else{
                int j = i + 1;
                while(j<nums1.size()){
                     if(nums1[j]%2!=0){
                        isOdd=true;
                         break;
                     }
                     j++;
                }

                if(isOdd!=true){
                    ans=true;
                }
                

               }

            }


        }

        return ans;
        
    }
};