class Solution {
public:
    int dfs(TreeNode* cur, TreeNode*& result , int goal1, int goal2){
        if(cur == nullptr){
            return 0;
        }
        //visit left, if 2, meaning lca is already assigned, in the left subtree
        int left = dfs(cur -> left, result, goal1, goal2);
        if(left == 2) {
            return 2;
        }
        //visit right, if 2, meaning lca is already assigned, in the right subtree
        int right = dfs(cur -> right, result, goal1, goal2);
        if(right == 2) {
            return 2;
        }
        //lca not yet appeared in the subtrees, might pr might not be current node
        int now = 0;
        if(cur->val == goal1 || cur->val == goal2){
            now = 1;
        } 
        //lca is current node
        if(now + left + right == 2){
            result = cur;
            return 2;
        }
        //lca not found yet (all node in tree with root cur)
        return now + left + right;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result;
        dfs(root, result, p->val, q->val);
        return result;
    }
};