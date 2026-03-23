// 75 leetcode challenge-->>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i>0 && arr[i-1]==arr[i]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(arr[i]+arr[j]+arr[k]==0){
                    temp.push_back(arr[i]);
                     temp.push_back(arr[j]);
                      temp.push_back(arr[k]);
                        ans.push_back(temp);
                        temp.clear();
                        j++;
                        k--;
                         // 🔥 correct place
                    while(j < k && arr[j] == arr[j-1]) j++;
                    while(j < k && arr[k] == arr[k+1]) k--;
                }
                else if(arr[i] + arr[j] + arr[k]>0){
                    k--;
                }
            
                else{
                    j++;
                }

            }

          
         

        }
        return ans;
        
    }
};


// Note point-->>
// hame ek element ek baar hi use karna hai
// kyu ki jab ek element ham le raha hai toh yoh sare pair jo bane sakrte hai yoh de deta hai toh hame uske dobara jarurat nahi ha'i