class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         vector<int> v;

    for (int num : nums) {
        if (v.empty() || num > v.back()) {
            v.push_back(num);
        }
        else {
            int left = 0, right = v.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (v[mid] < num) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
            v[left] = num;
        }
    }

    return v.size();
    }
};