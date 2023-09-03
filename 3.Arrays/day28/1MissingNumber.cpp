// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         //bruteforce
//         int n=nums.size()+1;
//         for(int i=0;i<n;i++){
//             int flag=0;
//             for(int j=0;j<n-1;j++){
//                 if(nums[j]==i){
//                     flag=1;
//                 }
//             }
//             if(flag==0){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// better
//  class Solution {
//  public:
//      int missingNumber(vector<int>& nums) {
//          int n=nums.size();
//          vector<int>frequency(n+1,0);
//          for(int i=0;i<nums.size();i++){
//              frequency[nums[i]]++;
//          }
//          for(int i=0;i<=n;i++){
//              if(frequency[i]==0){
//                  return i;
//              }
//          }
//          return -1;
//      }
//  };

// //optimal
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n=nums.size();
//         int sum=((n)*(n+1))/2;
//         int sum2=0;
//         for(int i=0;i<n;i++){
//             sum2+=nums[i];
//         }
//         return sum-sum2;
//     }
// };

// //optimal2 using xor
// //note/prereq: xor of same = 0, xor of any with 0=0
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int xor1=0,xor2=0;
//         int n=nums.size()+1;
//         for(int i=0;i<n;i++) xor1^=i;
//         for(int i=0;i<n-1;i++) xor2^=nums[i];
//         return xor1^xor2;
//     }
// };

// optimal2 using xor
// note/prereq: xor of same = 0, xor of any with 0=0
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int N = nums.size() + 1;
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < N - 1; i++)
        {
            xor2 = xor2 ^ nums[i]; // XOR of array elements
            xor1 = xor1 ^ (i + 1); // XOR up to [1...N]
        }

        return (xor1 ^ xor2); // the missing number
    }
};