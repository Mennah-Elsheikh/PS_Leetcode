class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) return true ; 
        else if  (n == 0) return false ;
        // else if (n % 4 != 0 )return false ;  
        else return (n % 4 == 0 || n == 4 ) && isPowerOfFour(n / 4 ); 
    }
    
};