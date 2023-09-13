// to find index of an element in array such that left sum equals right sum to that index
#include <iostream>
#include <vector>

int findBalanceIndex(const std::vector<int>& nums) {
    int totalSum = 0;
    int leftSum = 0;

    // Calculate the total sum of all elements in the array
    for (int num : nums) {
        totalSum += num;
    }

    for (int i = 0; i < nums.size(); ++i) {
        // Calculate the right sum by subtracting the left sum and the current element from the total sum
        int rightSum = totalSum - leftSum - nums[i];

        // Check if the left and right sums are equal
        if (leftSum == rightSum) {
            return i; // Index found
        }

        // Update the left sum for the next iteration
        leftSum += nums[i];
    }

    // If no index is found, return -1 to indicate no such index exists
    return -1;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 5, 2, 1};
    int balanceIndex = findBalanceIndex(nums);

    if (balanceIndex != -1) {
        std::cout << "Balance Index: " << balanceIndex << std::endl;
    } else {
        std::cout << "No balance index found." << std::endl;
    }

    return 0;
}
