class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char, int> appear;
        for (int i = 0; i < s.size(); i++) {
            appear[s[i]]++;
        }
        int length = 0;
        bool remains = false; 
        for (auto& count : appear) {
            if (count.second % 2 == 0) {
                length += count.second;
            } else {
                length += count.second - 1; 
                remains = true;
            }
        }

        if (remains) {
            length += 1; 
        }

        return length;
    }
};