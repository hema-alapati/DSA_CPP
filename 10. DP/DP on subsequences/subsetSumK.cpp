// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h> 

bool f(int ind, int target, vector<int>&arr){
    if(target==0) return true;
    if(ind==0) return(arr[0]==target);

    bool notTake=f(ind-1,target,arr);
    bool take=false;
    if(arr[ind]<=target) take=f(ind-1,target-arr[ind], arr);

    return take|notTake;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n-1,k,arr);
}
