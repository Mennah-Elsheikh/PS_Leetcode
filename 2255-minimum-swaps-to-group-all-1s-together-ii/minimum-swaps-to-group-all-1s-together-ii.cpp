class Solution {
public : 
int minSwaps(vector<int>& nums) {
    int ones = 0 ; 
    int n = nums.size();
    for(int i = 0 ; i < n ; i++)
    {
        if(nums[i] == 1) ones++; 
    }
    int cnt1 = 0;
    for (int i = 0; i < ones; ++i) {
        if (nums[i] == 1) {
            cnt1 += 1;
        }
    }
    int max1 = cnt1;
    for (int i = ones; i < n + ones; ++i) {
        if (nums[i % n] == 1) {
            cnt1 += 1;
        }
        if (nums[(i - ones) % n] == 1) {
            cnt1 -= 1;
        }
        max1 = max(max1, cnt1);
    }
    int ans = ones - max1;
    return ans;
}
};
