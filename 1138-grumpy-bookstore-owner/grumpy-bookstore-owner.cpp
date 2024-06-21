class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int initial_satisfaction = 0;
       int n = customers.size();
       for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0) {
            initial_satisfaction += customers[i];
          }
        }
    int max_gain = 0;
    int current_gain = 0;
    for (int i = 0; i < minutes; ++i) {
        if (grumpy[i] == 1) {
            current_gain += customers[i];
        }
    } 
    max_gain = current_gain;
    for (int i = minutes; i < n; ++i) {
        if (grumpy[i] == 1) {
            current_gain += customers[i];
        }
        if (grumpy[i - minutes] == 1) {
            current_gain -= customers[i - minutes];
        }
        
        max_gain = std::max(max_gain, current_gain);
    }
    return initial_satisfaction + max_gain;
    }
};