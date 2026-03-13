// 75LeetcodeChallenge-->>

// By using hash map-->>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==false){
                mp[nums[i]]=true;  
            }
            else{
                return true;
            }
        }
        return false;
       
    }
};