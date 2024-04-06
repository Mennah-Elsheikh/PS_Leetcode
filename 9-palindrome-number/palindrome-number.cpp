 #include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        else {
            
            int temp = x;
            int n = 0;
            while (temp > 0) {
                temp /= 10;
                n++;
            }
            
            vector<int> arr(n);
            int i = 0;
            while (x > 0) {
                int y = x % 10;
                arr[i] = y;
                i++;
                x /= 10;
            }
            
            for (int i = 0; i < n / 2; i++) {
                if (arr[i] != arr[n - i - 1]) {
                    return false;
                }
            }
            return true;
        }
    }
};
