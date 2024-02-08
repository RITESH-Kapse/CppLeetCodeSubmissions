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

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

    void preorderHelper(TreeNode* root, vector<int>& result) {
        // Base case: if root is null, return
        if (root == nullptr) {
            return;
        }

        // Visit current node
        result.push_back(root->val);

        // Traverse left subtree
        preorderHelper(root->left, result);

        // Traverse right subtree
        preorderHelper(root->right, result);

        }

};