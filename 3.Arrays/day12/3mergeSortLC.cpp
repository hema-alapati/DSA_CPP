class Solution
{
public:
    void merge(vector<int> &nums, int l, int m, int r)
    {
        int left = l;
        int right = m + 1;
        vector<int> temp;
        while (left <= m && right <= r)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= m)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= r)
        {
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = 0; i < temp.size(); i++)
        {
            nums[i + l] = temp[i];
        }
    }
    void mergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// class Solution {
// public:
//     void merge(int low, int mid, int high, vector<int> &nums) {
//         if (low >= high) return;
//         int l = low, r = mid + 1, k = 0, size = high - low + 1;
//         vector<int> sorted(size, 0);
//         while (l <= mid and r <= high)
//             sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
//         while (l <= mid)
//             sorted[k++] = nums[l++];
//         while (r <= high)
//             sorted[k++] = nums[r++];
//         for (k = 0; k < size; k++)
//             nums[k + low] = sorted[k];
//     }

//     void mergeSort(vector<int>& nums, int start, int end){
//         if(start < end){
//             int mid = start + (end - start) / 2;
//             mergeSort(nums, start, mid);
//             mergeSort(nums, mid + 1, end);
//             merge(start, mid, end, nums);
//         }
//     }

//     vector<int> sortArray(vector<int>& nums) {
//         mergeSort(nums, 0, nums.size()-1);
//         return nums;
//     }
// };   