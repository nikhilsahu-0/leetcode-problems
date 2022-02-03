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
    int sum = 0;
    
    void solve(TreeNode *root,int n){
        if(root->left == NULL && root->right == NULL){
            sum += n*10+root->val;
        }else{
            if(root->left == NULL)solve(root->right,(n*10)+root->val);
            else if(root->right == NULL)solve(root->left,(n*10)+root->val);
            else {
                solve(root->right,(n*10)+root->val);
                solve(root->left,(n*10)+root->val);
            }
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)return root->val;
        
        solve(root,0);
        return sum;
    }
};
