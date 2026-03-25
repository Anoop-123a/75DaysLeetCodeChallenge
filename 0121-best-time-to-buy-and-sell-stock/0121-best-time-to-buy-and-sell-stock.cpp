// 75 LeetcodeChallenge-->>

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // It is correct code but it time limit exceed
        //     int n = prices.size();
        //     int max_profit = 0;
        //     for (int i = 0; i < n; i++) {
        //         for (int j = i + 1; j < n; j++) {
        //             int current_profit = prices[j] - prices[i];
        //             if (max_profit < current_profit) {
        //                 max_profit = current_profit;
        //             }

        //         }
        //     }
        //     return max_profit;
        // }
        // };

        // Optimised Solution-->>
        int n = prices.size();
        int profit = 0;
        int single_day = prices[0];
        // let the day in which we buy a stock at minimum buying price.
        for (int i = 1; i < n; i++) {
            profit = max(profit, prices[i] - single_day);
            // compare current profit to our previous profit.
            single_day = min(single_day, prices[i]);
            // Update our single day
        }
        return profit;
    }
};