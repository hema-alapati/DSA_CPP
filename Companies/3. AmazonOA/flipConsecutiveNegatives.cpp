66qs,120mins
1 coding, rest all 5 mcqs on topics like data structures, algorithms, os, dbms, linux, networking, data visualization, pseudocodes, python mcqs, OOPS, etc.


// Question:
// The Card Game
// One day. Fred and his N friends were playing a card game in which each player throws a card with a number written on it. The cards are such that a number X is written on front of the card, and the negative of that number is written on the back side of the card. This game has the following rules: -
// Each of the N players is asked to throw a card. After all the N cards are thrown, Fred has to flip one or more cards in consecutive order, only once.
// Your task is to help Fred flip the cards in such a way that the sum of the numbers, on front face of the cards, is the maximum.
// Input Specification:
// input1: An integer N denoting the number of cards (1 <= N <= 500)
// input2: An integer array containing N integers, where the ith integer denotes the value on the front of the
// card (-1000 <= input2[i]< = 1000)
// Output Specification:
// Return the maximum sum of the numbers, on the front of the cards
// Example 1: input1: 5
// input2: (-2, 3, -1, -4, -2)
// Output: 8
// Explanation:
// Since Fred can flip consecutive cards only once, he chooses to flip the last three cards, which results in the maximum sum (-2 + 3 + 1 + 4 +2), i.e., 8.
// Therefore, 8 is returned as the output.
// Example 2: input1: 5
// input2: (-1. 2. 3, 4, -5)
// Output: 13


// question:
// array sum maximum cheyyali, danikosam consecutive ga unna negative numbers postive cheyocchu
// solution:
// maxsubarray sum chesinattu, minimum subarray sum chesi. total sum ki 2 time add chesthe negatives anni positive ayyi tootal sum ki add avthai


//logic
// 1. calculate consecutive negative sum that is least
// 2. for total sum, add modulus of this twice, this ensures that make all negatives 0 by adding once and adding postives of it by adding 2nd time

//code
#include<bits/stdc++.h>
using namespace std;

int minsubarraysum(int a[], int n) {
    int min_sum = INT_MAX;
    int curr_sum = 0;
    for (int i = 0 ; i < n; i++) {
        curr_sum = curr_sum + a[i];
        if (curr_sum < min_sum)
            min_sum = curr_sum;
        if (curr_sum > 0)
            curr_sum  = 0;
    }
    return min_sum;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int min_sum = minsubarraysum(a, n); //calculates consecutive negative sum that is least
    int ans = sum + (min_sum * (-2)); // for total sum, add modulus of this twice, this ensures that make all negatives 0 by adding once and adding postives of it by adding 2nd time
    cout << ans;
}

