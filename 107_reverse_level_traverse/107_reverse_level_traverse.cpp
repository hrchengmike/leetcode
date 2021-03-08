class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            vector<int> cur_v;
            for(int i = 0; i < count; i++){
                TreeNode* cur = q.front();
                q.pop();
                cur_v.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ans.push_back(cur_v);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};