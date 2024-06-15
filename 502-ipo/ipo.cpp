class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        /*
        [0 , 1, 1 ] 
        [1 , 2, 3 ]
        w = 0 , k = 2 
        w = 0 + 1 => k = 1 
        p[1] = p[2] 
        but pr[1] < p[2]
        w += pr[2] => k = 0 => return w ;
        */
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i] , profits[i]};
        }
        sort(projects.rbegin(), projects.rend());
        priority_queue<int> pq;
        while (k--) {
            while (!projects.empty() && projects.back().first<= w) {
                pq.push(projects.back().second);
                projects.pop_back();
            }
            if (pq.empty()) {
                break;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};