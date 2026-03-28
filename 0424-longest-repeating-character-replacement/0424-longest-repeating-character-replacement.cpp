// 75LeetCodeChallenge-->> 


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int i = 0, j = 0;
        int maxFreq = 0;
        int maxLength = 0;

        while (j < s.size()) {
            freq[s[j] - 'A']++;
            
            // update most frequent character count
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            // check if window valid hai
            if ((j - i + 1) - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }

            maxLength = max(maxLength, j - i + 1);
            j++;
        }

        return maxLength;
    }
};