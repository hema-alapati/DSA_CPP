// https://leetcode.com/problems/palindrome-number/submissions/
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int backup = x;
        long long y = 0;
        if (x >= 0)
        {
            while (x != 0)
            {
                y = (y * 10) + (x % 10);
                x = x / 10;
            }
            if (backup == y)
            {
                return true;
            }
        }
        return false;
    }
};