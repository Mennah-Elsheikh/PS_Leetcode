 class Solution {
public:
    int reverse(int x) {
        long long rx = 0; // Use long long to avoid overflow
        
        while (x != 0) {
            // Check for potential overflow before updating rx
            if (rx * 10 > INT_MAX || rx * 10 < INT_MIN) {
                return 0; // Return 0 if overflow would occur
            }
            
            rx = x % 10 + 10 * rx;
            x = x / 10;
        }
        
        // Check for potential overflow before returning rx
        if (rx > INT_MAX || rx < INT_MIN) {
            return 0; // Return 0 if overflow occurred
        }
        
        return rx;
    }
};
