class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
         for (int j = 0 ; j < n ; j++)
         {
          if(nums[i] == nums[j] && j < i )
          {
            count ++ ;
          }
         }
        
        }

        return count ; 
    }
};