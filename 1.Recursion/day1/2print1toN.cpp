#include <bits/stdc++.h>
using namespace std;

void printNumber(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << endl;
    printNumber(i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    printNumber(1, n);
    return 0;
}

// print linearly without using +

#include <bits/stdc++.h>
using namespace std;

void printLinear(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    printLinear(i - 1, n);
    cout << i << endl;
}

int main()
{
    int n;
    cin >> n;
    printLinear(n, n);
    return 0;
}