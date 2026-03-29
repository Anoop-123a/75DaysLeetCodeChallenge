// 75DayLeetCodeChallenge-->>


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '[' || ch == '{') {
                // case-1 opening bracket
                // insert
                st.push(ch);
            }

            else {
                // case-2 closing bracket
                // check with previous inserted bracket ->
                // for stack empty
                if (st .empty()) {
                    return false;
                }
                // 1- No match
                if (ch == ')' && st.top() != '(') {
                    return false;

                } else if (ch == '}' && st.top() != '{') {
                    return false;

                } else if (ch == ']' && st.top() != '[') {
                    return false;

                } else {
                    // match
                    st.pop();
                }
            }
        }
        // yaha par mein galti karta hoon
        if(st.empty()){
            // iska matlab sare bracket cancel out ho gya hai
            return true;
        }
        else{
            // cancel out hogya hai par kuch element bach gya hai
            return false;
        }  
        
          //or return s.empty();
    }
};