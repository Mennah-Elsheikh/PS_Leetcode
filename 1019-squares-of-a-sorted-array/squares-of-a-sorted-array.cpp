class Solution {
public:
vector<int> sortedSquares(vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    for(int i = 0  ; i < n ; i++)
    {
        squares[i] = arr[i] * arr[i];
    }
    sort(squares.begin() , squares.end());
    return squares;
    }
};