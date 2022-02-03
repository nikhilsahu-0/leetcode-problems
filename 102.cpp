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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        vector<vector<int>> vi;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp != NULL){
                v.push_back(temp->val);
                if(temp->left != NULL)q.push(temp->left);
                if(temp->right != NULL)q.push(temp->right);
            }else {
                
                vi.push_back(v);
                v = {};
                if(q.empty())break;
                q.push(NULL);
            }
        }
        return vi;
    }
};
