class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd = 0;
        for (int num : arr) {
            if (num % 2 == 0) {
                odd = 0;
            } else {
                odd++;
                if (odd == 3) {
                    return true;
                }
            }
        }
        return false;
    }
};
