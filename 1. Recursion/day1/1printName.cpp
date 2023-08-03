#include <bits/stdc++.h>
using namespace std;

void printNameRecursive(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << "Hemalatha" << endl;
    printNameRecursive(i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    printNameRecursive(1, n);
    return 0;
}