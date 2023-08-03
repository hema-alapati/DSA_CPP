// #include <bits/stdc++.h>
// using namespace std;

// int fib(int i)
// {
//     if (i <= 1)
//     {
//         return i;
//     }
//     return fib(i - 1) + fib(i - 2);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     cout << "fibonacci of " << n << " is:" << fib(n);
//     return 0;
// }

#include <iostream>
using namespace std;

int fib(int i)
{
    if (i <= 1)
    {
        return i;
    }
    return fib(i - 1) + fib(i - 2);
}

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << fib(n) << endl;
    }
    return 0;
}