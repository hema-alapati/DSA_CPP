// https://www.codingninjas.com/studio/problems/partition-equal-subset-sum-_892980?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

// from prev q https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
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


bool canPartition(vector<int> &arr, int n)
{
	int totSum=0;
	for(int i=0;i<n;i++) totSum+=arr[i];
	if(totSum%2) return false;
	int target=totSum/2;

	return subsetSumToK(n,target,arr);
	// Write your code here.
}
