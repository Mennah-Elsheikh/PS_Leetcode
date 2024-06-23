class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms ; 
        int p1 = 0 , p2 = 0 , ans = 0 ;
        while( p1 < nums.size())
        {
            ms.insert(nums[p1++]);
            while(*ms.rbegin()-*ms.begin() > limit)
            {
                ms.erase(ms.find(nums[p2++]));
            }
            ans = max(ans , p1-p2);
        }
        return ans ; 
    }
};