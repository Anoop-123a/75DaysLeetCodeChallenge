// Brute force-->>

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//       int n=s.size();
//       int i=0;
//       int j=0;
//       int maxLength=0;
//       map<char,bool>mp;
//       while(j<n){
//          if(mp[s[j]]!=false){
//             i=i+1;
//             j=i;
//             mp.clear();    
//          }
//          mp[s[j]]=true;
//            int length=j-i+1;
//           maxLength=max(length,maxLength);
//          j++;

//       }  
//       return maxLength;
//     }
// };

// optimal approach-->>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n=s.size();
      int i=0;
      int j=0;
      int maxLength=0;
      map<char,bool>mp;
      while(j<n){
         while(mp[s[j]]!=false){
            // jab tak duplicate  milega tab tak ham pich wale ek ek character remove karenga
            mp[s[i]]=false;   
            i++;
         }
           mp[s[j]]=true;
           int length=j-i+1;
          maxLength=max(length,maxLength);
         j++;

      }  
      return maxLength;
    }
};

