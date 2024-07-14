class Solution {
public:
    string countOfAtoms(string formula) {
        // Stack to hold maps of atom counts
        stack<map<string, int>> stk;
        stk.push(map<string, int>());  // Initialize with an empty map
        int n = formula.size();
        int idx = 0;

        while (idx < n) {
            if (formula[idx] == '(') {
                // Start of a new group
                stk.push(map<string, int>());
                idx++;
            } else if (formula[idx] == ')') {
                // End of a group
                int num = 0;
                idx++;
                // Read the multiplier after the ')'
                while (idx < n && isdigit(formula[idx]))
                    num = num * 10 + (formula[idx++] - '0');
                
                // Pop the map for the group and multiply counts
                auto curMap = stk.top();
                stk.pop();
                if (!num) num = 1;
                for (auto it : curMap) {
                    stk.top()[it.first] += it.second * num;
                }
            } else {
                // Reading an atom
                string atom = "";
                atom += formula[idx++];
                // Continue reading the atom name if it includes lowercase letters
                while (idx < n && islower(formula[idx]))
                    atom += formula[idx++];
                int num = 0;
                // Read the number following the atom name
                while (idx < n && isdigit(formula[idx]))
                    num = num * 10 + (formula[idx++] - '0');
                if (!num) num = 1;
                // Update the atom count in the current map
                stk.top()[atom] += num;
            }
        }

        // Build the result string
        string ans = "";
        for (auto it : stk.top()) {
            ans += it.first + (it.second > 1 ? to_string(it.second) : "");
        }
        return ans;
    }
};