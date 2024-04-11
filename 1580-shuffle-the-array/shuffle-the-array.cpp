class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
     vector<int> ans (2 * n);
     int x = 0 ;
     for (int i = 0 ; i < 2 * n ; i++)
    {
         if (i % 2 == 0) {
                ans[i] = nums[x];
            } else {
                ans[i] = nums[n + x];
                x++;
            }
    }
     return ans ;

    }
};