#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b)
        {
            if (c % 2 == 0)
            {
                cout << "Second" << endl;
            }
            else
            {
                cout << "First" << endl;
            }
        }
        else
        {
            if (a + c >= b + c)
            {
                cout << "First" << endl;
            }
            else if (a + c < b + c)
            {
                cout << "Second" << endl;
            }
        }
    }
    return 0;
}