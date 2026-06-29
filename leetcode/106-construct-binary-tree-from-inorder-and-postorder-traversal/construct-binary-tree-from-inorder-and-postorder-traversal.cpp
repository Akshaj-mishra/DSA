class Solution {
public:
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int left, int right) {

        if (left > right)
            return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];

        // Build right first
        root->right = build(inorder, postorder, mid + 1, right);
        root->left = build(inorder, postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};