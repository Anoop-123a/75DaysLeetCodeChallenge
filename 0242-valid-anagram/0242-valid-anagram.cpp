// 75dayLeetcodeChallenge-->>

class Solution {
public:
    bool isAnagram(string s, string t) {
          int num[1000] = {0};
    // for string s lets and up counts
    for (int k = 0; k < s.length(); k++) {
      char ch = s[k];
      num[ch] = num[ch] + 1;

      // It is the method by which we calculate the no of occurence of character
    }

    //  for string t , decrease the count
    for (int k = 0; k < t.length(); k++) {
      char ch = t[k];
      num[ch] = num[ch] - 1;
    }
    // check all occurences are 0 are not
    for (int k = 0; k < 1000; k++) {
      if (num[k] != 0) {
        return false;
      }
    }
    return true;
    }
};