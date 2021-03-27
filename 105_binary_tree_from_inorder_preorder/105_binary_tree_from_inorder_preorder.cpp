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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //only one node in both vector
        if(preorder.size() == 0){
            return nullptr;
        }
        //first element in pre-order is the root
        TreeNode* root = new TreeNode(preorder[0]);
        //find root id in inorder
        int id = 0;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == preorder[0]){
                id = i;
                break;
            }
        }
        
        vector<int> inorder_left(inorder.begin(), inorder.begin()+id);
        vector<int> inorder_right(inorder.begin()+id+1, inorder.end());
        vector<int> preorder_left(preorder.begin()+1, preorder.begin()+1+id);
        vector<int> preorder_right(preorder.begin()+1+id, preorder.end());
        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right, inorder_right);
        return root;
    }
    
};