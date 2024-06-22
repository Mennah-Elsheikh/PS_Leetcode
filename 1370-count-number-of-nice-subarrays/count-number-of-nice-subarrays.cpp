class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> prefix_counts;
    prefix_counts[0] = 1; 

    int result = 0;
    int odd_count = 0;

    for (int num : nums) {
        if (num % 2 == 1) {
            odd_count++;
        }

        if (prefix_counts.find(odd_count - k) != prefix_counts.end()) {
            result += prefix_counts[odd_count - k];
        }

        prefix_counts[odd_count]++;
    }

    return result;
    }
};