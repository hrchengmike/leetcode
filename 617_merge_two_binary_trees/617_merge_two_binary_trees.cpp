class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //both trees are null
        if(!t1 && !t2) return nullptr;
        //t1 null, t2 not null
        if(!t1) return t2;
        //t2 null, t1 not null
        if(!t2) return t1;
        //both trees not null
        TreeNode* root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    }
};