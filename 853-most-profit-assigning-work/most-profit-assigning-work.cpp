class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());   
        int max_profit = 0, ans = 0, j = 0;
        int n = worker.size() , m = jobs.size();
        for (int i = 0; i < n ; ++i) {
            while (j < m && worker[i] >= jobs[j].first) {
                max_profit = max(max_profit, jobs[j].second);
                ++j;
            }
            ans += max_profit;
        }   
        return ans;
    }
};