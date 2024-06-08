class Solution {
public:
    string clearDigits(string s) {
        stack<char> st; 
        for (char& x : s) {
            if (x >= '0' && x <= '9') {
                if (!st.empty()) st.pop(); 
                continue;  
            }
            st.push(x);  
        }
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
