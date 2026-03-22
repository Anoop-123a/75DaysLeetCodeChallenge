// 75leetcodechallenge-->>


// two pointer approach-->>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int>ans;
        int i=0;
        int j=n-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum>target){
                j--;
            }
            else if(sum<target){
                i++;

            }
            else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
                
            }
        }

        return ans;
 
        
    }
};

// Note point-->>
// Binary search are not work here b/c it is only used to search element 