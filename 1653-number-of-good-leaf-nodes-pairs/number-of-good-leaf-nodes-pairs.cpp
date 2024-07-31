/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int countPairs(TreeNode* root, int distance) {
    int ans = 0;
    dfs(root, distance, ans);
    return ans;
  }

private:
  vector<int> dfs(TreeNode* root, int distance, int& ans) {
    vector<int> d(distance + 1);  // {distance: the number of leaf nodes at this distance}
    if (root == nullptr)
      return d;
    if (root->left == nullptr && root->right == nullptr) {
      d[0] = 1;  // Leaf node is at distance 0
      return d;
    }

    const vector<int> dl = dfs(root->left, distance, ans);
    const vector<int> dr = dfs(root->right, distance, ans);

    // Count pairs of leaf nodes between left and right subtrees
    for (int i = 0; i < distance; ++i)
      for (int j = 0; j < distance; ++j)
        if (i + j + 2 <= distance)
          ans += dl[i] * dr[j];

    // Update the distances for the current node
    for (int i = 0; i < distance; ++i)
      d[i + 1] = dl[i] + dr[i];

    return d;
  }
};
