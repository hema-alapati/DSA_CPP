// https://leetcode.com/problems/merge-sorted-array/
// bruteforce
// tc o(m+n)+o(m+n)
// sc o(m+n)

// youtube
// https://www.codingninjas.com/studio/problems/merge-two-sorted-arrays-without-extra-space_6898839?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTab=1
// bruteforce
void merge(long long arr1[], long long arr2[], int n, int m)
{
    long long arr3[n + m];
    int left = 0;
    int right = 0;
    int index = 0;
    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else
        {
            arr3[index] = arr2[right];
            right++, index++;
        }
        while (left < n)
        {
            arr3[index++] = arr1[left];
            left++;
        }
        while (right < m)
        {
            arr3[index++] = arr2[right];
            right++;
        }
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            arr1[i] = arr3[i];
        else
            arr2[i - n] = arr3[i];
    }
}
// optimal
#include <vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    // Write your code here.
    int left = a.size() - 1;
    int right = 0;
    while (left >= 0 && right < b.size())
    {
        if (a[left] > b[right])
        {
            swap(a[left], b[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}
// leetcode, qs changed a bit
class Solution
{
public:
    // way3yt(https://www.youtube.com/watch?v=n7uwj04E0I4) time limit exceeded, takes o(min(m,n))+o(logn)
    //  void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    //      int left=n-1;
    //      int right=0;
    //      int index=n+m-1;
    //      while(left>=0 && right<m){
    //          if(nums1[left]>nums2[right]){
    //              nums1[index]=nums1[left];
    //              nums1[left]=nums2[right];
    //              index--;
    //              left--;
    //              right++;
    //          }
    //      }
    //      sort(nums1.begin(),nums2.end());
    //  }

    // way2 from solns
    //  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //      int i = m - 1;
    //      int j = n - 1;
    //      int k = m + n - 1;

    //     while (j >= 0) {
    //         if (i >= 0 && nums1[i] > nums2[j]) {
    //             nums1[k--] = nums1[i--];
    //         } else {
    //             nums1[k--] = nums2[j--];
    //         }
    //     }
    // }

    // way1 from solns
    //  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //      for(int i=m,j=0;j<n;j++){
    //          nums1[i++]=nums2[j];
    //      }
    //      sort(nums1.begin(),nums1.end());
    //  }
};