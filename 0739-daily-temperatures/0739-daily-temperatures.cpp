// 75LeetcodeChallenge-->>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { 
   int n=temperatures.size();
   stack<int>st;
   vector<int>ans(n,0);
   for(int i=n-1;i>=0;i--){

    while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
      st.pop();
      }

      if(!st.empty()){
          ans[i]=(st.top()-i);  //we store only answer index.
      }
       st.push(i);  //we push that index ith for next comparsion

   }
      
//Their is no need to reverse the ans vector because the ans is already in correct order
       return ans;  

    }
};

// Notes -->>
// we also do from left to right.