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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //base case
        if(root == NULL){
            return NULL;
        }

        //case 1 - p and q both are in left subtree of rootnode
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }

        //case 2 - both p and q in right subtree of root
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }

        // //case 3 - p in left and q in right subtree of root node
        // if(p->val < root->val && q->val > root->val){
        //     return root;
        // }

        // //case 4 - p in right and q in left subtree of root node
        // if(p->val > root->val && q->val < root->val){
        //     return root;
        // }

    return root;

    }
};