// https://leetcode.com/problems/a-number-after-a-double-reversal/submissions/

class Solution
{
public:
    bool isSameAfterReversals(int num)
    {
        int ans = 0;
        int temp = num;
        while (temp)
        {
            ans = ans * 10 + temp % 10;
            temp /= 10;
        }
        while (ans)
        {
            temp = temp * 10 + ans % 10;
            ans /= 10;
        }
        return temp == num;
    }
};