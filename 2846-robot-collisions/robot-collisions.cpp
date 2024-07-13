class Solution {
 public:
vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    vector<int> result;
    vector<int> idx(n);
    
    for (int i = 0; i < n; ++i) idx[i] = i;
    
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return positions[i] < positions[j];
    });
    
    stack<int> stk; // stack to keep the index of robots moving to the right
    
    for (int i : idx) {
        if (directions[i] == 'R') {
            stk.push(i);
        } else {
            while (!stk.empty() && healths[i] > 0) {
                int j = stk.top();
                if (healths[j] > healths[i]) {
                    --healths[j];
                    healths[i] = 0;
                } else if (healths[j] < healths[i]) {
                    --healths[i];
                    stk.pop();
                } else {
                    healths[i] = 0;
                    stk.pop();
                }
            }
            if (healths[i] > 0) result.push_back(i);
        }
    }
    
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }
    
    sort(result.begin(), result.end());
    
    vector<int> finalHealths;
    for (int i : result) finalHealths.push_back(healths[i]);
    
    return finalHealths;
}
};