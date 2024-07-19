class Solution {
public:
  vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> min_in_rows;
    vector<int> max_in_columns(matrix[0].size(), INT_MIN);
    
    // Step 1: Find the minimum element in each row
    for (const auto& row : matrix) {
        min_in_rows.push_back(*min_element(row.begin(), row.end()));
    }
    
    // Step 2: Find the maximum element in each column
    for (int j = 0; j < matrix[0].size(); ++j) {
        for (int i = 0; i < matrix.size(); ++i) {
            max_in_columns[j] = max(max_in_columns[j], matrix[i][j]);
        }
    }
    
    // Step 3: Find the elements that are both the minimum in their row and maximum in their column
    vector<int> lucky_numbers;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == min_in_rows[i] && matrix[i][j] == max_in_columns[j]) {
                lucky_numbers.push_back(matrix[i][j]);
            }
        }
    }
    
    return lucky_numbers;
  }
};