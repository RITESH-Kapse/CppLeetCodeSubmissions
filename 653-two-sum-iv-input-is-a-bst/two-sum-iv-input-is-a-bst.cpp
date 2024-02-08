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

    void storeInorder(TreeNode* root, vector<int> &inorder){

        //base case
        if(root == NULL){
            return;
        }

        //In Order - LNR
        //Left
        storeInorder(root->left, inorder);

        //Node
        inorder.push_back(root->val);

        //right
        storeInorder(root->right, inorder);

    }

    bool findTarget(TreeNode* root, int k) {

        vector<int> inorder; // to store the BST values in order
        storeInorder(root, inorder);

        //find target using 2-pointers in inorder vector
        int start = 0;
        int end = inorder.size()-1;

        while(start < end){

            int sum = inorder[start] + inorder[end];

            if(sum == k){
                return true;

            }else if(sum > k){
                end--;

            }else if(sum < k){
                start++;
            }

        }

        return false;
        
    }
};