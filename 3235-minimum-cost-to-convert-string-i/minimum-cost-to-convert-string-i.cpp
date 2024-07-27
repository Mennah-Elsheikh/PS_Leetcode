class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Floyd-Warshall algorithm to find minimum transformation cost
        vector<vector<int>> graph(26, vector<int>(26, 0x3f3f3f3f));

        // Initialize the graph with direct transformation costs
        for (int i = 0; i < 26; i++) {
            graph[i][i] = 0; 
        }
        
        int n = original.size();
        for (int i = 0; i < n; i++) {
            int src = original[i] - 'a'; // 0 -> 25 
            int dist = changed[i] - 'a'; 
            graph[src][dist] = min(cost[i], graph[src][dist]);
        }

        // Apply the Floyd-Warshall algorithm
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (graph[i][k] != 0x3f3f3f3f && graph[k][j] != 0x3f3f3f3f) {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }

        // Calculate the minimum cost to transform `source` to `target`
        long long totalCost = 0;
        if (source.size() != target.size()) {
            return -1; // Transformation is impossible if the lengths differ
        }
        
        for (size_t i = 0; i < source.size(); i++) {
            int src = source[i] - 'a';
            int dst = target[i] - 'a';
            if (graph[src][dst] == 0x3f3f3f3f) {
                return -1; // Transformation is impossible
            }
            totalCost += graph[src][dst];
        }

        return totalCost;
    }
};
