class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            }
            searchPair(nums, -nums[i], i + 1, triplets);
        }
        return triplets;
    }

private:
    void searchPair(const vector<int> &arr, int targetSum, int left, vector<vector<int>> &triplets) {
        int right = arr.size() - 1;
        while (left < right) {
            int currentSum = arr[left] + arr[right];
            if (currentSum == targetSum) { // found the pair
                triplets.push_back({-targetSum, arr[left], arr[right]});
                left++;
                right--;
                while (left < right && arr[left] == arr[left - 1]) {
                    left++; // skip same element to avoid duplicate triplets
                }
                while (left < right && arr[right] == arr[right + 1]) {
                    right--; // skip same element to avoid duplicate triplets
                }
            } else if (currentSum < targetSum) {
                left++; // we need a pair with a bigger sum
            } else {
                right--; // we need a pair with a smaller sum
            }
        }
    }
};
