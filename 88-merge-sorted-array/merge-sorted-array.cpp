class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Index for the last element in the initial part of nums1
        int j = n - 1; // Index for the last element in nums2
        int k = m + n - 1; // Index for the last position in nums1
        
        // Start merging from the end of nums1 and nums2
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        // If there are remaining elements in nums2, copy them
        while (j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};
