#include <iostream>
#include "../bst.h"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val_p = p -> val;
        int val_q = q -> val;
        TreeNode* cur = root;
        while(true){
            //If curent node value equals one of the target, return current
            if(val_p == cur -> val || val_q == cur -> val){
                return cur;
            }
            //If one of the target greater than, the other target smaller than current, return current
            if((cur -> val - val_p)*(cur -> val - val_q) < 0){
                return cur;
            }
            //Otherwise, two targets on the same side, update current to its child
            if(cur -> val - val_p > 0 && cur -> val - val_q > 0){
                cur = cur -> left;
            }
            if(cur -> val - val_p < 0 && cur -> val - val_q < 0){
                cur = cur -> right;
            }
        }
    }
};

int main(){
    Solution s;
    int v []= {5, 1, 4, 0, 0, 3, 6};
    TreeNode* root = init_tree(v, 7);
    cout << "Tree (in order traversal): \n";
    print_tree(root);
    cout << "Lowest Common Ancester of 6 and 1: \n";
    cout << s.lowestCommonAncestor(root, root->left, root->right->right)->val << endl;
    delete_tree(root);
    return 0;
}