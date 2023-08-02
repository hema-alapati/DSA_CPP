#include <bits/stdc++.h>
using namespace std;

void printNumber(int i, int n)
{
    if (n < i)
    {
        return;
    }
    cout << n << endl;
    printNumber(i, n - 1);
}

int main()
{
    int n;
    cin >> n;
    printNumber(1, n);
    return 0;
}