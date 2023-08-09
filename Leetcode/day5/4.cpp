// https://leetcode.com/problems/move-zeroes/
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int nonZeroIndex = 0; // Pointer to the current position to place the next non-zero element

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[nonZeroIndex] = nums[i]; // Move non-zero element to the correct position
                nonZeroIndex++;
            }
        }

        // Fill the remaining positions with zeroes
        while (nonZeroIndex < nums.size())
        {
            nums[nonZeroIndex] = 0;
            nonZeroIndex++;
        }
    }
};
