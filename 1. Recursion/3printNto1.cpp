// #include <bits/stdc++.h>
// using namespace std;

// void printNumber(int i, int n)
// {
//     if (n < i)
//     {
//         return;
//     }
//     cout << n << endl;
//     printNumber(i, n - 1);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     printNumber(1, n);
//     return 0;
// }

// print n to 1 without -

#include <bits/stdc++.h>
using namespace std;

void printnto1(int i, int n)
{
    if (i > n)
    {
        return;
    }
    printnto1(i + 1, n);
    cout << i << endl;
}

int main()
{
    int n;
    cin >> n;
    printnto1(1, n);
    return 0;
}