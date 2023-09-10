// https://leetcode.com/problems/single-number/solutions/1771720/c-easy-solutions-sorting-xor-maps-or-frequency-array/


class Solution {
public:
// the elements with frequency=2 will result in 0. And then the only element with frequency=1 will generate the answer.
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            ans^=it;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i=1;i<nums.size();i+=2){
//             if(nums[i]!=nums[i-1]){
//                 return nums[i-1];
//             }
//         }  
//         return nums[nums.size()-1];
//     }
// };


//extra space
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int>a;
//         for(auto it:nums){
//             a[it]++;
//         }
//         for(auto it:a){
//             if(it.second==1) return it.first;
//         }
//         return -1;
//     }
// };

