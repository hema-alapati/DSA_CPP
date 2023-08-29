// https://leetcode.com/problems/longest-consecutive-sequence/description/
//better
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int longest=1;
        int lastSmaller=INT_MIN;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastSmaller){
                cnt++;
                lastSmaller=nums[i];
            }
            else if(nums[i]!=lastSmaller){
                cnt=1;
                lastSmaller=nums[i];
            }
            longest=max(cnt,longest);
        }
        return longest;
    }
};

//bruteforce
// class Solution {
// public:
//     bool linearSearch(vector<int>nums, int x){
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==x) return true;
//         }
//         return false;
//     }
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();
//         int longest=1;
//         for(int i=0;i<n;i++){
//             int x=nums[i];
//             int count=1;
//             while(linearSearch(nums,x+1)){
//                 x+=1;
//                 count++;
//             }
//             longest=max(count,longest);
//         }
//         return longest;
//     }
// };