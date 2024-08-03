class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0 , n = nums.size();
        for(int l = 0 ; l < n ; l++)
        {
        for(int r = l + 1  ; r < n ; r++)
        {
            if(nums[l] + nums[r] < target) count++;
        }
        }
        return count ;
    }
};