class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0 )
        return false ; 
        int countones = __builtin_popcount(n);
        return (countones == 1 );
    }
};