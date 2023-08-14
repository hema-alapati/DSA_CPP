#include <bits/stdc++.h>
using namespace std;

bool palindrome(int i, string &s)
{
    if (i >= s.size() / 2)
    {
        return true;
    }
    if (s[i] != s[s.size() - i - 1])
    {
        return false;
    }
    palindrome(i + 1, s);
}

int main()
{
    string s;
    cin >> s;
    if (palindrome(0, s))
    {
        cout << s << " is a palindrome";
    }
    else
    {
        cout << "Not a palindrome!";
    }
    return 0;
}