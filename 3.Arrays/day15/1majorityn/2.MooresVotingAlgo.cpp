class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cnt1 = 0, cnt2 = 0;
        int el1, el2;
        vector<int> ls;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && nums[i] != el2)
            {
                cnt1++;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != el1)
            {
                cnt2++;
                el2 = nums[i];
            }
            else if (nums[i] == el1)
                cnt1++;
            else if (nums[i] == el2)
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        int mini = (int)(n / 3) + 1;
        int tempcnt1 = 0, tempcnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el1)
                tempcnt1++;
            else if (nums[i] == el2)
                tempcnt2++;
        }
        if (tempcnt1 >= mini)
            ls.push_back(el1);
        if (tempcnt2 >= mini)
            ls.push_back(el2);
        return ls;
    }
};