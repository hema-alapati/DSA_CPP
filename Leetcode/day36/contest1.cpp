// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-operations-to-collect-elements/
// You are given an array nums of positive integers and an integer k. In one operation, you can remove the last element of the array and add it to your collection.
// Return the minimum number of operations needed to collect elements 1, 2, ..., k.

 
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        set<int> uniqueElements;
        int foundUniqueCount = 0;

        for (int i=nums.size()-1;i>=0;i--) {
            if (nums[i] <= k) {
                uniqueElements.insert(nums[i]);
            }
            count++;

            if (uniqueElements.size() == k) {
                foundUniqueCount = 1;
                break;
            }
        }

        if (foundUniqueCount == 1) {
            return count;
        }

        return -1;
    }
};
