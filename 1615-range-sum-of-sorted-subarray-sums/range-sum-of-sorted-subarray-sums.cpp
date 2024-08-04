class Solution {
public:
    int rangeSum(std::vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            for (int j = i; j < n; j++) {
                currentSum += nums[j];
                sum.emplace_back(currentSum);
            }
        }
        nth_element(sum.begin(), sum.begin() + left - 1, sum.end());
        nth_element(sum.begin() + left - 1, sum.begin() + right, sum.end());
        //sort(sum.begin() + left - 1, sum.begin() + right);
        int ans = 0;
        int MOD = 1000000007;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sum[i]) % MOD;
        }
        return ans;
    }
};
