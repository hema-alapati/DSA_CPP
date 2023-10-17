// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h> 
// Recursion
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

// -------------------------------------------------------------------------------

#include <bits/stdc++.h> 
//Memoization
bool f(int ind, int target, vector<int>&arr,vector<vector<int>>&dp){
    if(target==0) return true;
    if(ind==0) return(arr[0]==target);

    if(dp[ind][target]!=-1) return dp[ind][target];

    bool notTake=f(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target) take=f(ind-1,target-arr[ind], arr,dp);

    return dp[ind][target]=take|notTake;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

// -------------------------------------------------------------------------------------
// tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=take|notTake;
        }
    }
    return dp[n-1][k];
}

// -------------------------------------------------------------------------------------------
// space optimization
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k+1,0),cur(k+1,0);
    prev[0]=cur[0]=true;
    prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake=prev[target];
            bool take=false;
            if(arr[ind]<=target) take=prev[target-arr[ind]];
            cur[target]=take|notTake;
        }
        prev=cur;
    }
    return prev[k];
}

// -------------------------------------------------------------------------------------------
