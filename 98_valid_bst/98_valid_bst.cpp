//Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <deque>
#include "../bst.h"
using namespace std;

class Solution {
private:
    void inorder(TreeNode* node, vector<int>& result){
        if (!node) return; 
        inorder(node -> left, result);
        result.push_back(node -> val);
        inorder(node -> right, result);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        //for (int i = 0; i < result.size(); i++) cout << result[i] << endl;
        for(int i = 0; i < result.size()-1 ; i++)
            if(!(result[i] < result[i+1])) return false;
        return true;
    }
};

int main(){
    Solution s;
    int v []= {5, 1, 4, 0, 0, 3, 6};
    TreeNode* root = init_tree(v, 7);
    print_tree(root);
    cout << "is valid BST? " << s.isValidBST(root) << endl;
    delete_tree(root);
    //cout << "result: "<< result << endl;
    return 0;
}