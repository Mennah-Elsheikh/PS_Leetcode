class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
            // Calculates the maximum importance of the cities based on the roads
        // Create a vector to store the degree (number of roads) for each city
        vector<int> degreeCounts(n, 0);

        // Iterate through each road to increment the degree of the two cities connected by the road
        for (const auto& road : roads) {
            ++degreeCounts[road[0]];
            ++degreeCounts[road[1]];
        }

        // Sort the degree counts in non-decreasing order
        sort(degreeCounts.begin(), degreeCounts.end());

        // Initialize a variable to store the maximum importance sum
        long long maxImportance = 0;

        // Assign the importance to each city based on its degree count
        // The city with the smallest degree gets an importance of 1, the next one gets 2, and so on
        for (int i = 0; i < n; ++i) {
            maxImportance += static_cast<long long>(i + 1) * degreeCounts[i];
        }

        // Return the calculated maximum importance sum
        return maxImportance;
    }
};