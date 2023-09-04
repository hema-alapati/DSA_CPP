// https://leetcode.com/problems/reverse-words-in-a-string/submissions/

class Solution {
public:
    string reverseWords(string s) {
        stack <string> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            string word="";
            while (i < n && s[i] == ' ') {
                i++; // Skip leading spaces
            }
            if (i >= n) {
                break;
            }
            while(s[i]!=' '&&i<s.length()){
                word+=s[i];
                i++;
            }
            st.push(word);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if (!st.empty()) {
                ans += ' '; // Add a space if there are more words in the stack
            }
        }
        
        return ans;
    }
};