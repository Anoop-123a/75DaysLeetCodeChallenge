// Time complexity-->>O(nlogn)
// Better approach-->>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> v; //make for storing map second value
        vector<int> ans; // answer vector 
        map<int, pair<int, int>> mp; //map
        // cout the frequency of every element of input vector-->>
        for (int i = 0; i < n; i++) {
            int digit = nums[i];
            mp[digit].first = digit;
            mp[digit].second = mp[digit].second + 1;
        }

        // pushing map second value(i.e;pair) in to v vector-->>
        for (auto it : mp) {
            v.push_back(it.second);
        }

        // sort the vector on the basis of frequency in descending order-->>
        sort(v.begin(), v.end(),[](auto& a, auto& b)
         {  return a.second > b.second; });

    //    pushing the first value of v vector-->> 
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};


// It is also solve by bucket sort-->>
// optimal approach-->>