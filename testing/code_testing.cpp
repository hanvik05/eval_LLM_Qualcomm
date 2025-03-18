#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the maximum element in a vector
int findMax(const std::vector<int>& nums) {
    int maxVal = nums[0]; // Potential issue: No check for empty vector
    for (int i = 1; i <= nums.size(); i++) { // Bug: Should be i < nums.size()
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    return maxVal;
}

// Function to sort a vector (Buggy)
void sortVector(std::vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); i++) {
        for (size_t j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) { // Bug: Should be nums[j] < nums[i] for ascending order
                std::swap(nums[i], nums[j]);
            }
        }
    }
}

// Function to print a vector
void printVector(const std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6};
    
    std::cout << "Original vector: ";
    printVector(numbers);
    
    int maxVal = findMax(numbers);
    std::cout << "Maximum value: " << maxVal << std::endl;
    
    sortVector(numbers);
    std::cout << "Sorted vector: ";
    printVector(numbers);
    
    return 0;
}
