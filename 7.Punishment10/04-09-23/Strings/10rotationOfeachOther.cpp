// https://leetcode.com/problems/rotate-string/solutions/118696/c-java-python-1-line-solution/

// concatenate it with same and find if B is there in A
class Solution
{
public:
    bool rotateString(string A, string B)
    {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};