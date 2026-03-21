// 75Leetcode challenge-->>


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // For counting the non digit
        int count = 0;
        for (int i = 0; i < n; i++) {
            // First place the non digit number into vector
            if (nums[i] != 0) {
                nums[count++] = nums[i];
            }
        }
        // Then fill the zero after the filling non-digit number
        for (int i = count; i < n; i++) {
            nums[i] = 0;
        }
    }
};