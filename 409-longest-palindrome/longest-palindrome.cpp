class Solution {
public:
    int longestPalindrome(string s) {
         stack<char> st;
        sort(s.begin() , s.end());
        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        int unmatched = st.size();
        int length = s.size() - unmatched;
        if (unmatched > 0) {
            length += 1;
        }    
        return length;
    }
};