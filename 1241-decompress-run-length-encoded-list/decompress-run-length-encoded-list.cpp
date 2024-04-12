class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
     int n = nums.size();
     vector<int> ans ;    
     for( int  i = 0 ; i < n / 2  ; i++)
     { 
       int freq = nums[2 * i ] ; 
       int val = nums[ (2 * i ) + 1];
    
        while(freq--)
        {
            ans.push_back(val);
        }
     }
     return ans ;  
    }
};