class Solution {
public:
    string reversePrefix(string word, char ch) {
        int r = 0; 
        // Find the first occurrence of 'ch'
        while (r < word.size() && word[r] != ch) {
            r++;
        }
        // If 'ch' is not found, return the original word
        if (r == word.size()) {
            return word;
        }
        // Reverse the prefix
        int l = 0;
        while (l < r) {
            swap(word[l], word[r]);
            l++;
            r--;
        }
        return word;
    }
};
