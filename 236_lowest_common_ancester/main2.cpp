/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* cur, stack<TreeNode*>& path, int goal){
        if(cur == nullptr){
            return false;
        }
        
        if(dfs(cur -> left, path, goal) || dfs(cur -> right, path, goal)){
            path.push(cur);
            //cout << cur->val << endl;
            return true;
        }
        if(cur -> val == goal){
            path.push(cur);
            //cout << cur->val << endl;
            return true;
        }
        return false;
    }
    
    stack<TreeNode*> path2node(TreeNode* root, TreeNode* p){
        stack<TreeNode*> path;
        dfs(root, path, p->val);
        return path;
    }
    
    void print_path(stack<TreeNode*>& path){
        cout << "start printing ";
        while(!path.empty()){
            cout << path.top()->val << " ";
            path.pop();
        }
        cout << endl;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> path_p = path2node(root, p);
        //print_path(path_p);
        stack<TreeNode*> path_q = path2node(root, q);
        //print_path(path_q);
        TreeNode* lca;
        while(!path_p.empty() && !path_q.empty() && path_p.top()->val == path_q.top()->val){
            lca = path_p.top();
            path_p.pop();
            path_q.pop();
        }
        return lca;
    }
};