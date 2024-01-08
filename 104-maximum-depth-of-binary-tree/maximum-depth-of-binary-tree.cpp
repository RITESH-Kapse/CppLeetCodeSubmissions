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
    int maxDepth(TreeNode* root) {

        //base case
        if(root==NULL){
            return 0;
        }

        //solve 1 case
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        //left wala and right wale mese jo max hai usme root node ka 1 add kardo
        int height = max(leftHeight, rightHeight) + 1;
        
        return height;
        
    }
};