int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum=0;
	for(int i=0;i<n;i++) totSum+=arr[i];

	int k=totSum;
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

	
	// prev[col-> 0..totSum]	 will give answer
	int mini=1e9;
	for(int s1=0;s1<=totSum/2;s1++){
		if(prev[s1]==true){
			mini=min(mini,abs((totSum-s1)-s1));
		}
	}
	return mini;
}
