// https://leetcode.com/problems/remove-outermost-parentheses/submissions/

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string res;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' && count == 0)
            {
                count++;
            }
            else if (s[i] == '(' && count >= 1)
            {
                res += s[i];
                count++;
            }
            else if (s[i] == ')' && count == 1)
            {
                count--;
            }
            else if (s[i] == ')' && count > 1)
            {
                res += s[i];
                count--;
            }
        }
        return res;
    }
};