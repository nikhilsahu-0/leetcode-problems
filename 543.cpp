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
    int height(TreeNode* root, int &di){
        if(root == NULL)return 0;
        else {
            int l = height(root->left,di);
            int r = height(root->right,di);
            
            di = max(di,l+r);
            return max(l,r)+1;
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int di = 0;
        height(root,di);
        return di;
    }
};
