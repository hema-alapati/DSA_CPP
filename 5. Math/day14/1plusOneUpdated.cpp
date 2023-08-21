// https://leetcode.com/problems/plus-one/submissions/

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                digits[i]++;
            }
            // if the current digit it 9, it becomes 10 so 0 at current and adding 1 to previous digit
            if (digits[i] == 10)
            {
                digits[i] = 0;
                // whenever it's not the first digit, we can directly add one to it
                if (i != 0)
                {
                    digits[i - 1]++;
                }
                else
                {
                    // for 999 case, it should become 1000 so pushing back a 0 and changing current digit to 1
                    digits.push_back(0);
                    digits[i] = 1;
                }
            }
        }
        return digits;
    }
};