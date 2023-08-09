// https://leetcode.com/problems/contains-duplicate/
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;

        for (int num : nums)
        {
            if (seen.count(num) > 0)
            {
                return true; // Found a duplicate
            }
            else
            {
                seen.insert(num); // Add the element to the set
            }
        }

        return false; // No duplicates found
    }
};
