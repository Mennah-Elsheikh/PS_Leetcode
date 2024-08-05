class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
        unordered_map<string, int> mp;
        for(string x : arr) {
            mp[x]++;
        }
        for(auto& s : arr) {
            if(mp[s] == 1 && --k == 0)
                return s;
        }
        return "";
    }
};