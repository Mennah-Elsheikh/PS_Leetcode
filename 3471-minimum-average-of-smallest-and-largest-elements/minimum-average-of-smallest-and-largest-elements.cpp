class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        double ans = DBL_MAX; 
        int l = 0, r = n - 1;
        sort(nums.begin(), nums.end());
        
        while (l < r) {
            double currentAverage = (nums[l] + nums[r]) / 2.0;
            ans = min(ans, currentAverage);
            l++;
            r--;
        }
        
        // Edge case: If there's only one element in the array
        if (n == 1) {
            return nums[0];
        }
        
        return ans;
    }
};
