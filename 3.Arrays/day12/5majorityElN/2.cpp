class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int el;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                el = nums[i];
                cnt = 1;
            }
            else if (nums[i] == el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return el;
    }
};