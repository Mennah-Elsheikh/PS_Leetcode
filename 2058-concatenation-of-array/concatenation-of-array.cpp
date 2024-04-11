class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans (2 * n); 
        for(int i = 0 ; i <n ; i++)
        {
            ans[i] = nums[i];
        }
         for(int i = 0 ; i <n ; i++)
        {
            ans[n + i] = nums[i];
        }
        return ans;

        
    }
};