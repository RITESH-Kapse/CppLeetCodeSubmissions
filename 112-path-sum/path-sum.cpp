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

    bool solve(TreeNode* root, int targetSum, int sum){

        //base case
        if(root == NULL){
            return false;

        }

        //har node pe sum plus karte hai
        sum+=root->val;

        //when at leaf node
        if(root->left == NULL && root->right == NULL){

            //verify sum with target
            if(sum==targetSum){
                return true;
            }else{
                return false;
            }
        }

        //get left right ans with recursion
        bool leftAns = solve(root->left, targetSum, sum);
        bool rightAns = solve(root->right, targetSum, sum);

        //true or false --> true -- hence using OR operation to send true at top.
        return leftAns||rightAns;


    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;        
    }
};