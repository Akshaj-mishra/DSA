/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool mirror(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;

        if (!left || !right)
            return false;

        return left->val == right->val &&
               mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return mirror(root->left, root->right);
    }
};