// 75LeetCodeChallenge-->>

class Solution {
public:
 bool isvalidCharacter(char ch){
    if(ch>='0' && ch<='9'){
        return true;
    }
    if(ch>='a'&& ch<='z'){
        return true;
    }
     if(ch>='A'&& ch<='Z'){
        return true;
    }
    return false;
 }
     string normalisedString(string& s){
        // remove every character except
        // alphabet
        // and number
        string newStr="";
        for(int i=0;i<s.length();i++){
            char ch =s[i];
            if(isvalidCharacter(ch)){
                if(ch>='A' && ch <='Z'){
                   ch=ch-'A'+'a'; 
                }
                newStr.push_back(ch);
            }
        }
        return newStr;
     }
     
    bool isPalindrome(string s) {
         string str=normalisedString(s);
           int i=0;
           int j=str.length()-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            else{
              i++;
              j--;
            }

        }
        return true;
    }
};