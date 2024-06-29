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
    int sumOfLeftLeaves(TreeNode* root) {
         if (!root)
            {
                return 0;
            }
            int sum = 0;
            if (root->left && !root->left->left && !root->left->right) // here it is the left node and have no children in the right and left(leave node )
            {
                sum += root->left->val; // Add the value of the left leaf node
            }
            // Recursively find the sum of left leaves in both left and right subtrees
            return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right); // to traverse over the tree to reach the leave node
    }
};