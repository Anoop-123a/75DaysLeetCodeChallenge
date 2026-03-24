// 75Leetcode challenge-->>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int n=height.size();
        int left=0;
        int right=n-1;
        while(left<right)
        {
            int width=right-left;
            int h=min(height[left],height[right]); //Minimum Height
            int current_area=h*width; //Current Area 
             maxArea=max(maxArea,current_area);  
            //Compare maximum area with current area.

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }

        }
        return maxArea;
   
        
    }
};