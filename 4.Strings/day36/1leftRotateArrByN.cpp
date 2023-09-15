class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        int temp[k];
        for (int i = 0; i < k; i++)
        {
            temp[i] = nums[i];
        }
        for (int i = k; i < n; i++)
        {
            nums[i - k] = nums[i];
        }
        for (int i = n - k; i < n; i++)
        {
            nums[i] = temp[i - (n - k)];
        }
    }
};