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
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vi;
        vector<int> v;
        
        if(!root)return {};
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        int level = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                
                if(level == 1){
                    reverse(v.begin(),v.end());
                    level = 0;
                }else level = 1;
                vi.push_back(v);
                v = {};
                if(q.empty())break;
                q.push(NULL);
            }else{
                v.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        
        return vi;
    }
};
