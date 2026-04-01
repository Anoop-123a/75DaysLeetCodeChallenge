// 75DayLeetcodeChallenge-->>


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();
        st.push(stoi(tokens[0]));
        for(int i=1;i<n;i++){
        string element=tokens[i];
      if(element=="+" || element=="-" || 
               element=="*" || element=="/"){

                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if(element=="+") st.push(a+b);
                else if(element=="-") st.push(a-b);
                else if(element=="*") st.push(a*b);
                else st.push(a/b);
            }

              else{
                st.push(stoi(element));
              }
              
        }

       return st.top();
        
    }
};

// Note point-->>
// 1- Reverse Polish Notation is a postfix expression.
// logic-->>
// 1-Create stack
// 2-Traverse tokens
// 3-If number → push
// 4-If operator:
// :  pop 2 values
// :  calculate
// :  push result
// 5-Final answer = stack top