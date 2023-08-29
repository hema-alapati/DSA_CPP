// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

int maxLen(vector<int> &A, int n)
{
    // Your code here
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]); // if the sum already exists in hashmap, find current index-index where that sum was previously found
            }
            else
            {
                mpp[sum] = i; // if the sum doesn't exist, just put it in hashmap
            }
        }
    }
    return maxi;
};