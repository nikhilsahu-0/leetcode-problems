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
    
    bool check(TreeNode* root, int t, int sum){
        if(root->left == NULL && root->right == NULL){
            return sum+root->val == t;
        }else {
            if(root->left != NULL && root->right != NULL)return check(root->left,t,sum+root->val) || check(root->right,t,sum+root->val);
            else if(root->left == NULL) return check(root->right,t,sum+root->val);
            else return check(root->left,t,sum+root->val);
        }
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
            if(root == NULL)return false;
            return check(root,targetSum,0);
    }
};
