
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        auto check = [&](vector<int>& v, int mid) {
            int num = m - 1; 
            int last = v[0];
            for (int i = 1; i < v.size(); ++i) {
                if (v[i] - last >= mid) {
                    num--;
                    last = v[i]; 
                    if (num == 0) {
                        return true;
                    }
                }
            }
            return num <= 0; 
        };

        int low = 1, high = 1e9, mid, ans = -1; 

        while (low <= high) {
            mid = (low + high) / 2; 
            if (check(position, mid)) { 
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }

        return ans;
    }
};