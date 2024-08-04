class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            for (int j = i; j < n; j++) {
                currentSum += nums[j];
                sum.emplace_back(currentSum);
            }
        }
        sort(sum.begin(), sum.end());
        int ans = 0;
        int MOD = 1000000007;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sum[i]) % MOD;
        } 
        return ans;
    }
};
