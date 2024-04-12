class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefixsum(n);
        prefixsum[0] = nums[0] ; 
        for(int i = 1 ; i < n ; i++)
        {
            prefixsum[i] = nums[i] + prefixsum[i - 1];
        }
        return prefixsum ; 
    }
};