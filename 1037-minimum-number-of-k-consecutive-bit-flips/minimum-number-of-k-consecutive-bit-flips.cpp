class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> isFlipped(n, 0);
    int flips = 0, flip = 0;
    for (int i = 0; i < n; ++i) {
        if (i >= k) flip ^= isFlipped[i - k]; // Check if out-of-window flip needs to be reversed
        if (nums[i] == flip) { // If nums[i] is 0 after applying the cumulative flip effect
            if (i + k > n) return -1; // If flipping from this position is not possible
            isFlipped[i] = 1; // Mark this position for a flip
            flip ^= 1; // Apply the flip
            flips++;
        }
    }
    return flips;
    }
};