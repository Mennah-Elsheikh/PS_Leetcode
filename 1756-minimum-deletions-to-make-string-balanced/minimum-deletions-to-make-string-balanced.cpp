class Solution {
public:
  // Same as 926. Flip String to Monotone Increasing
  int minimumDeletions(string s) {
    int dp = 0; // The number of characters to be deleted to make the substring so far balanced
    int countB = 0; // The count of 'b' characters encountered so far

    for (const char c : s) {
      if (c == 'a') {
        // Case 1: Delete the current 'a'
        // Case 2: Keep the current 'a' and delete all previous 'b's
        dp = min(dp + 1, countB);
      } else {
        ++countB; // Increment the count of 'b' characters
      }
    }

    return dp; // Return the minimum deletions required
  }
};
