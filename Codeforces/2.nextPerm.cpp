#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> permutation(n);
        for (int i = 0; i < n; ++i)
        {
            permutation[i] = i + 1;
        }

        // Swap adjacent elements to maximize score
        for (int i = 0; i < n - 1; i += 2)
        {
            swap(permutation[i], permutation[i + 1]);
        }

        // Print the permutation
        for (int i = 0; i < n; ++i)
        {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
