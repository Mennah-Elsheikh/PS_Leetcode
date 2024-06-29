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
class Solution
    {
    public:
        int maxDepth(TreeNode *root)
        {
            int maxDepth = 0; // Initialize the maximum depth
            int count = 0;    // Initialize the current depth counter
            dfs(root, count, maxDepth);
            return maxDepth;
        }

    private:
        void dfs(TreeNode *node, int count, int &maxDepth)
        {
            if (node == NULL)
                return;
            count++; // Increment counter to reflect current depth
            if (count > maxDepth)
            {
                maxDepth = count; // Update maximum depth
            }
            dfs(node->left, count, maxDepth);
            dfs(node->right, count, maxDepth);
        }
    };