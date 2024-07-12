class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;

        // Helper lambda function to remove substrings and calculate points
        auto removeSubstring = [](std::string &str, char first, char second, int points) {
            string remaining;
            int score = 0;
            for (char ch : str) {
                if (!remaining.empty() && remaining.back() == first && ch == second) {
                    remaining.pop_back(); // Found a matching substring
                    score += points;
                } else {
                    remaining.push_back(ch);
                }
            }
            str = remaining;
            return score;
        };

        // Prioritize the higher score first
        if (x > y) {
            totalScore += removeSubstring(s, 'a', 'b', x);
            totalScore += removeSubstring(s, 'b', 'a', y);
        } else {
            totalScore += removeSubstring(s, 'b', 'a', y);
            totalScore += removeSubstring(s, 'a', 'b', x);
        }

        return totalScore;
    }
};