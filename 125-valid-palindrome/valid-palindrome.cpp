/*
    Given a string s, return true if it's a palindrome
    Ex. s = "A man, a plan, a canal: Panama" -> true

    2 pointers, outside in, skip non-letters & compare

    Time: O(n)
    Space: O(1)
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            // Skip non-alphanumeric characters from the left
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            // Skip non-alphanumeric characters from the right
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            // Compare characters
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};
