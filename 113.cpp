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
    
    vector<vector<int>> vi;
    vector<int> v;
    
    void check(TreeNode* root, int t, int sum){
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
            if(sum + root->val == t)vi.push_back(v);
            v.pop_back();
        }else {
            v.push_back(root->val);
            if(root->left == NULL)check(root->right,t,sum+root->val);
            else if(root->right == NULL)check(root->left,t,sum+root->val);
            else {
                check(root->right,t,sum+root->val);
                check(root->left,t,sum+root->val);
            }
            v.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return {};
        check(root,targetSum,0);
        return vi;
    }
};
