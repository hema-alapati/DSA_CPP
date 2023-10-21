// https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

//rec
int countSubsets(int i, int sum, vector<int>arr){
	if(sum==0) return 1;
	if(i==0) return (arr[i]==sum);

	int notPick=countSubsets(i-1,sum,arr);
	int pick=0;
	if(arr[i]<=sum) pick=countSubsets(i-1,sum-arr[i],arr);

	return pick+notPick;
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	return countSubsets(n-1,k,arr);

}


//memoization
int countSubsets(int i, int sum, vector<int>&arr,vector<vector<int>>&dp){

	if(sum==0) return 1;
	if(i==0) return (arr[i]==sum);
	
	if(dp[i][sum] != -1){
		return dp[i][sum];
	}
	int notPick=countSubsets(i-1,sum,arr,dp);
	int pick=0;
	if(arr[i]<=sum) pick=countSubsets(i-1,sum-arr[i],arr,dp);

	return dp[i][sum]=pick+notPick;
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return countSubsets(n-1,k,arr,dp);
}


//tabulation

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,0));
	// return countSubsets(n-1,k,arr,dp);
	for(int i=0;i<n;i++){
		dp[i][0]=1;
	}
	if(arr[0]<=k) dp[0][arr[0]]=1;
	for(int i=1;i<n;i++){
		for(int sum=0;sum<=k;sum++){
			int notPick=dp[i-1][sum];
			int pick=0;
			if(arr[i]<=sum) pick=dp[i-1][sum-arr[i]];

			dp[i][sum]=pick+notPick;
		}
	}
	return dp[n-1][k];
}


//space optimization

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<int>prev(k+1,0),cur(k+1,0);
	prev[0]=cur[0]=1;
	if(arr[0]<=k) prev[arr[0]]=1;
	for(int i=1;i<n;i++){
		for(int sum=0;sum<=k;sum++){
			int notPick=prev[sum];
			int pick=0;
			if(arr[i]<=sum) pick=prev[sum-arr[i]];

			cur[sum]=pick+notPick;
		}
		prev=cur;
	}
	return prev[k];
}
