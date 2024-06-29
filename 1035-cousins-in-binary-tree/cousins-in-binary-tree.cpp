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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        queue<pair<TreeNode*, TreeNode*>> q; // {node, parent}
        q.push({root, nullptr});

        TreeNode* xParent = nullptr;
        TreeNode* yParent = nullptr;
        int xDepth = -1;
        int yDepth = -1;
        int depth = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) {
                    xParent = parent;
                    xDepth = depth;
                }
                if (node->val == y) {
                    yParent = parent;
                    yDepth = depth;
                }

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }
            
            if (xParent && yParent) break;
            depth++;
        }

        return (xDepth == yDepth) && (xParent != yParent);
    }
};