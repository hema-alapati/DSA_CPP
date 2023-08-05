class Solution
{

public:
    void func(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset)
    {
        // base case: when no more indices(elemnts) are left to decide(pick)
        //  decide:decide whether to pick or not the next element
        if (ind == N)
        {
            sumSubset.push_back(sum);
            return;
        }
        // pick the element
        func(ind + 1, sum + arr[ind], arr, N, sumSubset);
        // do not pick the element
        func(ind + 1, sum, arr, N, sumSubset);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> sumSubset;
        func(0, 0, arr, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
};