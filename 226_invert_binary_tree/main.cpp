#include <iostream>
#include "../bst.h"
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        //swap left and right child, where one of them or none of them can be null 
        TreeNode* temp = root -> left;    //cout << "result: "<< result << endl;
        root -> left = root -> right;
        root -> right = temp;
        //invert right/left subtree, if it is null, already handled in the first case(do nothing)
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};

int main(){
    Solution s;
    int v []= {5, 1, 4, 0, 0, 3, 6};
    TreeNode* root = init_tree(v, 7);
    cout << "Before inversion (in order traversal): \n";
    print_tree(root);
    cout << "After inversion (in order traversal): \n";
    print_tree(s.invertTree(root));
    delete_tree(root);
    return 0;
}