class Solution {
public:
  vector<string> solveUsingRec(
        string s,
        vector<string>& wordDict,
        vector<string> result,
        int start,
        string current,
        unordered_map<string, int>& mp
    ) {
        // Base case
        if (start == s.size()) {
            result.push_back(current);
            return result;
        }

        string word;

        for (int i = start; i < s.size(); i++) {
            word += s[i];

            if (mp.find(word) != mp.end()) {
                string newCurrent;

                if (current.empty()) {
                    newCurrent = word;
                } else {
                    newCurrent = current + " " + word;
                }

                vector<string> temp = solveUsingRec(
                    s, wordDict, {}, i + 1, newCurrent, mp
                );

                result.insert(
                    result.end(), temp.begin(), temp.end()
                );
            }
        }

        return result;
    }



    vector<string> solveUsingMemo(string s, vector<string>& wordDict,
                                 vector<string> result, int start,
                                 string current,
                                 unordered_map<string, int>& mp,  unordered_map<string, vector<string>>&dp) {

        // Base case-->>
        if (start == s.size()) {
            result.push_back(current);
            return result;
        }
           // Memoization key: start + current
        string key = to_string(start) + "#" + current;

         if (dp.find(key) != dp.end()) {
            return dp[key];
        }


        string word;
        for (int i = start; i < s.size(); i++) {
            word = word + s[i];
            string newCurrent;
            if (mp.find(word) != mp.end()) {
                if(current.size()==0){
                    newCurrent=word;
                }
                else{
                    newCurrent=current+" "+word;
                }

                 vector<string> temp =
                    solveUsingMemo(s, wordDict, {}, i + 1, newCurrent, mp,dp);
                result.insert(result.end(), temp.begin(), temp.end());
               
            }

       
    }
    dp[key]=result;
    return result;

}

vector<string>
wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, int> mp;
    int n=s.size();
    for (auto it : wordDict) {
        mp[it] = 1;
    }
    vector<string> result;
    string current;
    // return solveUsingRec(s, wordDict, result, 0, current, mp);
      unordered_map<string, vector<string>> dp;
    return solveUsingMemo(s, wordDict, result, 0, current, mp,dp);
}
}
;