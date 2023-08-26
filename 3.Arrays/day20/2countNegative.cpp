// https://leetcode.com/submissions/detail/1032124238/

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] < 0)
                    count++;
            }
        }
        return count;
    }

    // optimal
    class Solution
    {
    public:
        int countNegatives(vector<vector<int>> &grid)
        {
            int ans = 0;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = grid[0].size() - 1; j >= 0; j--)
                {
                    if (grid[i][j] < 0)
                        ans++;
                    else
                        break;
                }
            }
            return ans;
        }
    };