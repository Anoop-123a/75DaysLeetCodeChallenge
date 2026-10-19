class Solution {
public:
    bool SolvingUsingRec(vector<int>& stones, int index, int k, int prevValue) {
        // Base case-->>
        if (index == stones.size() - 1) {
            return true;
        }

        bool firstAns = false;
        bool secondAns = false;
        bool thirdAns = false;
        int element1 = stones[index];

        if (prevValue + k == stones[index]) {
            int jump = k + 1;
            int element2 = element1 + jump;
            auto it = find(stones.begin(), stones.end(), element2);
            if (it != stones.end()) {
                int nextIndex = it - stones.begin(); // convert into integer
                firstAns = SolvingUsingRec(stones, nextIndex, jump, element1);
            }
        }
        if (k - 1 > 0) {
            if (prevValue + k == stones[index]) {
                int jump = k - 1;
                int element2 = element1 + jump;
                auto it = find(stones.begin(), stones.end(), element2);
                if (it != stones.end()) {
                    int nextIndex = it - stones.begin(); // convert into integer
                    secondAns =
                        SolvingUsingRec(stones, nextIndex, jump, element1);
                }
            }
        }
        if (prevValue + k == stones[index]) {
            int jump = k;
            int element2 = element1 + jump;
            auto it = find(stones.begin(), stones.end(), element2);
            if (it != stones.end()) {
                int nextIndex = it - stones.begin(); // convert into integer
                thirdAns = SolvingUsingRec(stones, nextIndex, jump, element1);
            }
        }

        return firstAns | secondAns | thirdAns;
    }

    bool SolvingUsingMemo(vector<int>& stones, int index, int k, int prevValue,
                          vector<vector<int>>& dp) {
        // Base case-->>
        if (index == stones.size() - 1) {
            return true;
        }

        if (dp[index][k] != -1) {
            return dp[index][k];
        }

        bool firstAns = false;
        bool secondAns = false;
        bool thirdAns = false;
        int element1 = stones[index];

        if (prevValue + k == stones[index]) {
            int jump = k + 1;
            int element2 = element1 + jump;
            auto it = find(stones.begin(), stones.end(), element2);
            if (it != stones.end()) {
                int nextIndex = it - stones.begin(); // convert into integer
                firstAns =
                    SolvingUsingMemo(stones, nextIndex, jump, element1, dp);
            }
        }
        if (k - 1 > 0) {
            if (prevValue + k == stones[index]) {
                int jump = k - 1;
                int element2 = element1 + jump;
                auto it = find(stones.begin(), stones.end(), element2);
                if (it != stones.end()) {
                    int nextIndex = it - stones.begin(); // convert into integer
                    secondAns =
                        SolvingUsingMemo(stones, nextIndex, jump, element1, dp);
                }
            }
        }
        if (prevValue + k == stones[index]) {
            int jump = k;
            int element2 = element1 + jump;
            auto it = find(stones.begin(), stones.end(), element2);
            if (it != stones.end()) {
                int nextIndex = it - stones.begin(); // convert into integer
                thirdAns =
                    SolvingUsingMemo(stones, nextIndex, jump, element1, dp);
            }
        }

        dp[index][k] = firstAns | secondAns | thirdAns;
        return dp[index][k];
    }

    bool SolvingUsingTab(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // stone value -> index
        unordered_map<int, int> stoneIndex;
        for (int i = 0; i < n; i++) {
            stoneIndex[stones[i]] = i;
        }
        // You take n + 1 columns because k itself can be n.
        // fill base case dp array-->>
        for (int i = 0; i <= n; i++) {
            dp[n - 1][i] = true;
        }

        for (int index = n - 2; index >= 1; index--) {
            for (int k = n; k >= 1; k--) {

                bool firstAns = false;
                bool secondAns = false;
                bool thirdAns = false;
             int currentStone = stones[index];

                //    for k+1-->

                int jump = k + 1;
                if (jump <= n) {
                    int nextStone = currentStone + jump;
                    if(stoneIndex.find(nextStone) != stoneIndex.end()) {
                         int nextIndex = stoneIndex[nextStone];
                        firstAns = dp[nextIndex][jump];
                    }
                }

                //    for k-1-->>

                if (k - 1 > 0) {
                    int jump = k - 1;
                 int nextStone = currentStone + jump;
                     if(stoneIndex.find(nextStone) != stoneIndex.end()) {
                         int nextIndex = stoneIndex[nextStone];
                        secondAns = dp[nextIndex][jump];
                    }
                }

                // for k-->>
                jump = k;
               int nextStone = currentStone + jump;
                if(stoneIndex.find(nextStone) != stoneIndex.end()) {
                         int nextIndex = stoneIndex[nextStone];
                        thirdAns = dp[nextIndex][jump];
                    }
                dp[index][k] = firstAns | secondAns | thirdAns;
            }
        }

        return dp[1][1];
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int k = 1;
        if (stones.size() < 2 || stones[1] != 1) {
            return false;
        }
        int prevValue = stones[0];
        // bool ans=SolvingUsingRec(stones,1,k,prevValue);
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //  bool ans=SolvingUsingMemo(stones,1,k,prevValue,dp);
        bool ans = SolvingUsingTab(stones);
        return ans;
    }
};