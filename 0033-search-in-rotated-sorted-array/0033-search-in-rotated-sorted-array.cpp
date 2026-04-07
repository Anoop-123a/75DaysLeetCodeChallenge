// 75 Leetcode challenge-->>

class Solution {
public:
        int findPivotIndex(vector<int>& nums) {
            // code here
            int n = nums.size();
            int s = 0;
            int e = n - 1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                // single number in vector
                if(s==e){
                    return mid;
                }
                // mid is on ans
                if (mid + 1 < n && nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                if (nums[mid] < nums[s]) {
                    // left
                    e = mid - 1;
                } else {
                    // right
                    s = mid + 1;
                }
            }

            // agar main line 25 tak aagya ,toh iska matlab hai mujhe pivot element nhi mila matlab mujhe return karna hai -1
            return -1;
        }

        int binarySearch(int s, int e, vector<int>& nums, int target) {
            while (s <= e) {
                int mid = (s + e) / 2;
                if (nums[mid] == target) {
                    return mid;
                }
                if (target > nums[mid]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
            return -1;
        }

    int search(vector<int>& nums, int target) {
            int pivot_index = findPivotIndex(nums);
            int n = nums.size();
            // 2 sorted array hai(a1 and a2)
            // a1-->
            // s=0
            // e=pivot index
            if (target >= nums[0] && target <= nums[pivot_index]) {
                int ans = binarySearch(0, pivot_index, nums, target);
                return ans;
            }
            // a2-->
            // s=pivot index +1
            // e=n-1
            else {
                int ans = binarySearch(pivot_index + 1, n - 1, nums, target);
                return ans;
            }
            return -1;
        }
    };