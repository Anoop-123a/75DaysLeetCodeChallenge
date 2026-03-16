
 class Solution {
public:
      vector<vector<string>> groupAnagrams(vector<string>& strs) {
     map<string, vector<string >>map;

     for(auto str:strs){
        string s=str;
        sort(s.begin(),s.end());
         map[s].push_back(str);
        //  it add value str associated with key s.
        
     }
     vector<vector<string>>ans;
     for(auto it=map.begin();it!=map.end();it++){
     ans.push_back(it->second);
    }
    return ans;
 }

};


// Note point-->>
// it->first → refers to the key

// it->second → refers to the value
