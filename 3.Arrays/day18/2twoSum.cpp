// https://leetcode.com/problems/two-sum/submissions/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        sort(nums.begin(), nums.end());
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == target)
            {
                return true;
            }
            else if (sum < target)
                left++;
            else
                right--;
        }
        return false;
    }
};

// better using hashmap
//  class Solution {
//  public:
//      vector<int> twoSum(vector<int>& nums, int target) {
//          map<int,int>mpp;
//          int n=nums.size();
//          for(int i=0;i<n;i++){
//              int a=nums[i];
//              int more=target-a; //how much more is required to make the target
//              if(mpp.find(more)!=mpp.end()){
//                  return {mpp[more],i};
//              }
//              mpp[a]=i;
//          }
//          return {};
//      }
//  };

// brute force
//  class Solution {
//  public:
//      vector<int> twoSum(vector<int>& nums, int target) {
//          vector<int>result;
//          for(int i=0;i<nums.size();i++){
//              for(int j=i+1;j<nums.size();j++){
//                  if(nums[i]+nums[j]==target){
//                      result.push_back(i);
//                      result.push_back(j);
//                  }
//              }
//          }
//          return result;
//      }
//  };