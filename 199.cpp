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
    vector<int> vi;
    
    void solve(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        TreeNode *curr = root,*prev = root;
        while(!q.empty()){
            prev = curr;
            curr = q.front();
            q.pop();
            if(curr == NULL){
                vi.push_back(prev->val);
                if(q.empty())break;
                q.push(NULL);
            }else{
                if(curr->left != NULL)q.push(curr->left);
                if(curr->right != NULL)q.push(curr->right);
            }
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)return {};
        solve(root);
        return vi;
    }
};
