class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[n + i]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int>ans;
//         int j=n;
//         for(int i=0;i<n;i++){
//             ans.push_back(nums[i]);
//             ans.push_back(nums[j++]);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int>ans;
//         int i=0,j=n;
//         while((i<n)&&(j<2*n)){
//             ans.push_back(nums[i]);
//             ans.push_back(nums[j]);
//             i++,j++;
//         }
//         return ans;
//     }
// };