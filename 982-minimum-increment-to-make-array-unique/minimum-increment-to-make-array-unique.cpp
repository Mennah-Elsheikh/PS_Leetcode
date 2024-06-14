class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        /*
        [1 , 2 , 2] => [1 , 2 , 3]
        [3 , 2 , 1 , 2 , 1 , 7 ] => [ 3 , 4 , 1 , 2 , 5 , 7]
        Mmmmmm [1 , 1 , 2 , 2 , 3 , 7 ] => [1 , 1+1 , 2+1 , 2+2 , 3+2 , 7]
        */
        int n  = nums.size();
        int count = 0 ; 
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n - 1 ;  i++)
        {
            int increment = 0 ; 
            if(nums[i+1] <= nums[i])
            {
                increment = (nums[i] - nums[i+1]) + 1 ;
                nums[i+1] += increment ;
                count += increment ; 
            }
        }
        return count ; 
    }
};