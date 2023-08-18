// https://leetcode.com/problems/missing-number/

// bf https://www.youtube.com/watch?v=2D0D8HE6uak
void findDupandMissing(vector<int> &nums)
{
    int n = nums.size();
    int repeated = -1, missing = -1;
    for (int i = 1; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == i)
            {
                count++;
            }
        }
        if (count == 2)
            repeated = i;
        if (count == 0)
            missing = i;
        if (repeated != -1 && missing != -1)
        {
            break;
        }
    }
}

// hash array
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Write your code here
    int n = a.size();
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            repeating = i;
        else if (hash[i] == 0)
            missing = i;
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {repeating, missing};
}