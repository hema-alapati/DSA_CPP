class Solution {
public:
    bool check(vector<int>& nums) {
        int i=0;
        for(i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                return false;
            }
        }
        return true;
    }
};
