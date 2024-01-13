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

    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftheight = height(root->left);
        int rightheight = height(root->right);

        int finalAns = max(leftheight, rightheight) + 1;

        return finalAns;

    }


    bool isBalanced(TreeNode* root) {

        // kisi bhi node pe jake dekho - left subtree and right subtree me height diff is 0 or max 1 then its balanced subtree

        //base case
        if(root == NULL){
            return true;
        }

        //currNode - Solve
        int rightheight = height(root->right);
        int leftheight = height(root->left);

        int diff = abs(leftheight - rightheight);

        bool currNode = (diff <= 1);

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);


        //agar left , right and curr node pe height < = 1 hai to true return karenege
        if(currNode && leftAns && rightAns){
            return true;
        }else{
            return false;
        }
        
    }
};