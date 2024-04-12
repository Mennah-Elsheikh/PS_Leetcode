 #include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> prefixsum(n + 1);
        prefixsum[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefixsum[i] = gain[i - 1] + prefixsum[i - 1];
        }
        return *max_element(prefixsum.begin(), prefixsum.end());
    }
};
