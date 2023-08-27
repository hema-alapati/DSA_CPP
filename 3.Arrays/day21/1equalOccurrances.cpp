// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/submissions/

class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        vector<int> alpha(26);
        for (int i = 0; i < s.length(); i++)
        {
            alpha[s[i] - 'a']++;
        }
        int standard = -1;
        for (int i = 0; i < 26; i++)
        {
            if (standard == -1 && alpha[i] != 0)
            {
                standard = alpha[i];
            }
            else if (standard != -1 && alpha[i] != 0)
            {
                if (alpha[i] != standard)
                    return false;
            }
        }
        return true;
    }
};