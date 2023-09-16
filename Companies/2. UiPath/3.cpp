// A string s comprised of digits from O to 9 contains a perfect substring if all the elements
// within a substring occur exactly k times. Calculate the number of perfect substrings in s.
// Example
// 5 = 1102021222
// k=2
// The 6 perfect substrings are:
// 1. S[0:1] = 11
// 2. S[0:5] = 110202
// 3. S[1:6] = 102021
// 4. S[2:5] = 0202
// 5. S[7:8] = 22
// 6. S[8:9] = 22

#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<int> &arr, int k)
{
    for (int val : arr)
    {
        if (val != 0 && val != k)
        {
            return false;
        }
    }
    return true;
}

int perfectSubstring(string s, int k)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        vector<int> arr(10, 0); // Initialize an array of size 10 to count occurrences of digits 0 to 9.
        for (int j = i; j < s.length(); j++)
        {
            if (j > i + (10 * k))
            {
                break;
            }
            char ch = s[j];
            arr[ch - '0']++; // Increment the count for the corresponding digit.
            if (check(arr, k))
            {
                res++;
            }
        }
    }
    return res;
}

int main()
{
    string s = "1102021222";
    int k = 2;

    int result = perfectSubstring(s, k);

    cout << "The number of perfect substrings is: " << result << endl;

    return 0;
}

// Java
// public static boolean check(int[] arr, int k) {
//     for (int val : arr) {
//         if (val != 0 && val != k)
//             return false;
//     }
//     return true;
// }

// public static int perfectSubstring(String s, int k) {
//     int res = 0;
//     for (int i = 0; i < s.length(); i++) {
//         int[] arr = new int[10];
//         for (int j = i; j < s.length(); j++) {
//             if (j > i + (10 * k))
//                 break;
//             char ch = s.charAt(j);
//             arr[ch - '0']++;
//             if (check(arr, k))
//                 res++;
//         }
//     }
//     return res;
// }