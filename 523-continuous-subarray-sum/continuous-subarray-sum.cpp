class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        unordered_map<int, int> modIndexMap; 
        modIndexMap[0] = -1; 
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int currMod = (k == 0) ? prefixSum : (prefixSum % k);

            if (modIndexMap.find(currMod) != modIndexMap.end()) {
                if (i - modIndexMap[currMod] > 1) {
                    return true;
                }
            } else {
                modIndexMap[currMod] = i;
            }
        }
        return false;
    }
};
