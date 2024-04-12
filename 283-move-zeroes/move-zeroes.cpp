class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_zero_index = 0 ; 
        int n = nums.size();
        for (int i = 0 ; i < n ; i++)
        {
            if( nums[i] != 0 )
            {
                nums[last_zero_index] = nums[i];
                last_zero_index++ ; 
            }
        }
        for(int i = last_zero_index ; i < n ; i++)
        {
            nums[i] = 0 ;
        } 

    }
};