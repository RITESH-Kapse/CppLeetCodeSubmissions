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
    TreeNode* searchBST(TreeNode* root, int val) {

        //1 case hum sabhalte
        if (root == nullptr || root->val == val) {
            return root; // Return root if root is null or its value is val
        }

        //baki recursion pe chodte
        if (val < root->val) {
            return searchBST(root->left, val); // Search in the left subtree
        } else {
            return searchBST(root->right, val); // Search in the right subtree
        }
    }
        
};
