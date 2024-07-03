class Solution {
public:
    int minDifference(vector<int>& nums) {
     // If the array length is less than or equal to 4, we can make all elements equal with at most 3 moves
    if (nums.size() <= 4) {
        return 0;
    }

    // Sort the array
    sort(nums.begin(), nums.end());

    // Calculate the minimum difference in the four scenarios

    // Scenario 1: Change the three largest elements to the value of the fourth largest element
    int diff1 = nums[nums.size() - 4] - nums[0];
    // Scenario 2: Change the two largest elements and the smallest element
    int diff2 = nums[nums.size() - 3] - nums[1];
    // Scenario 3: Change the largest element and the two smallest elements
    int diff3 = nums[nums.size() - 2] - nums[2];
    // Scenario 4: Change the three smallest elements to the value of the fourth smallest element
    int diff4 = nums[nums.size() - 1] - nums[3];

    // Return the minimum difference among the four scenarios
    return min({diff1, diff2, diff3, diff4});
    }
};