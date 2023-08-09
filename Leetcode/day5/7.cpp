// https://leetcode.com/problems/maximum-product-subarray/solutions/3186637/best-c-2-solution-dp-brute-force-optimize-one-stop-solution/
#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int maxProduct = INT_MIN;
    int temp = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        temp *= nums[i];
        maxProduct = max(maxProduct, temp);
        if (temp == 0)
        {
            temp = 1;
        }
    }
    temp = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        temp *= nums[i];
        maxProduct = max(maxProduct, temp);
        if (temp == 0)
        {
            temp = 1;
        }
    }
    return maxProduct;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int ans = maxProduct(nums);
    cout << ans << " is the ans";
    return 0;
}