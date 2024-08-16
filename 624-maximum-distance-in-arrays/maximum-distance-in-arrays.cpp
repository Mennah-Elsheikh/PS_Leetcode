class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = INT_MAX, mx = INT_MIN, n = arrays.size(), ans = 0; 
        for (int i = 0; i < n; i++) {
            int sz = arrays[i].size();
             if (mn != INT_MAX) {
                ans = max(ans, arrays[i][sz-1] - mn); 
            }
            if (mx != INT_MIN) {
                ans = max(ans, mx - arrays[i][0]);
            }
            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i][sz-1]);
        }
        return ans; 
    }
};