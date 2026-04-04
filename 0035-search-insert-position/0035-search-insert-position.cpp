// 75 leetcode challenge-->>


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Linear search to find target
        int n =nums.size();
        for(int i=0;i<n;i++){//it will be done in one loop
            if(nums[i]>=target){ // if found or target smaller
                return i;
            }
        }
        return n ;// if target is greater than all elements
    }
        
    
};