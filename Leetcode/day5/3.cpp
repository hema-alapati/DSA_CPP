
// https://leetcode.com/problems/roman-to-integer/submissions/
class Solution
{
public:
    int romanToInt(string s)
    {
        int total = 0;
        unordered_map<char, int> umap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (umap[s[i]] < umap[s[i + 1]])
            {
                total -= umap[s[i]];
            }
            else
            {
                total += umap[s[i]];
            }
        }
        total += umap[s[s.length() - 1]];
        return total;
    }
};