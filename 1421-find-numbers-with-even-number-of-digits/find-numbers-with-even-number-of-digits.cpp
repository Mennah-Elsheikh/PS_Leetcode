class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0 ; 
        for(int i = 0 ; i < n ; i++)
        {
            if(numdigit(nums[i]) % 2 == 0 )
            {
                count ++ ; 
            }
        }
        return count ; 
        
    }
    int numdigit(int num)
    {
        int count = 0 ; 
        while(num)
        {
           num /= 10 ;
           count++;
        }
        return count ; 
    }
};