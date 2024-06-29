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
    struct NodeInfo {
        TreeNode* parent;
        int depth;
    };

    void dfs(TreeNode* node, TreeNode* parent, int depth, int val, NodeInfo &info) {
        if (!node) {
            return;
        }
        if (node->val == val) {
            info = {parent, depth};
            return;
        }
        dfs(node->left, node, depth + 1, val, info);
        dfs(node->right, node, depth + 1, val, info);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) {
            return false;
        }

        NodeInfo infoX = {nullptr, 0};
        NodeInfo infoY = {nullptr, 0};

        dfs(root, nullptr, 0, x, infoX);
        dfs(root, nullptr, 0, y, infoY);

        // Check if the nodes are at the same depth but have different parents
        return (infoX.depth == infoY.depth) && (infoX.parent != infoY.parent);
    }
};