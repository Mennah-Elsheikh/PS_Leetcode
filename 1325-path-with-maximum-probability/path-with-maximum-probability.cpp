class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start, int end) {
    // Graph representation: node -> [(neighbor, probability)]
    vector<vector<pair<int, double>>> graph(n);
    // Max-heap (priority queue) to store the current best probabilities
    priority_queue<pair<double, int>> maxHeap;
    maxHeap.emplace(1.0, start);
    vector<bool> seen(n);

    // Build the graph from edges and succProb
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i][0];
      int v = edges[i][1];
      double prob = succProb[i];
      graph[u].emplace_back(v, prob);
      graph[v].emplace_back(u, prob);
    }

    // Process the nodes
    while (!maxHeap.empty()) {
      auto [prob, u] = maxHeap.top();
      maxHeap.pop();
      
      // If the end node is reached, return the probability
      if (u == end)
        return prob;
      
      // If this node has been seen before, skip it
      if (seen[u])
        continue;
      
      // Mark the node as seen
      seen[u] = true;
      
      // Explore the neighbors
      for (const auto& [nextNode, edgeProb] : graph[u]) {
        if (!seen[nextNode])
          maxHeap.emplace(prob * edgeProb, nextNode);
      }
    }

    // If the end node is unreachable, return 0
    return 0;
  }
};
