//Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <deque>
#include "../bst.h"
using namespace std;

void delete_tree (TreeNode* root){
    deque <TreeNode*> q;
    q.push_back(root);
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop_front();
        if(cur->left!=nullptr) q.push_back(cur->left);
        if(cur->right!=nullptr)q.push_back(cur->right);
        delete cur;
    }
}

void print_tree(TreeNode* node){
    if(node->left != nullptr) print_tree(node->left);
    cout << "node in tree: " << node->val << endl;
    if(node->right != nullptr) print_tree(node->right);
}
//this function initialize a tree based on an array of positive integer node vals(can contain 0 which is null)
TreeNode* init_tree(int vals [], int length){
    deque<TreeNode*> q;
    TreeNode* root = new TreeNode(vals[0]);
    q.push_back(root);
    int idx = 1;// the index of next vals element
    while(idx < length){
        TreeNode* parent = q.front();
        q.pop_front();
        //parent is null
        if(!parent) {
            idx += 2;//the next two elements in array have to be null since null cannot have child
            continue;
        }
        //parent is not null
        //assign left child (initialize new node if not null)
        if(vals[idx]){
            TreeNode* left_child = new TreeNode(vals[idx++]);
            parent->left = left_child;
            q.push_back(left_child);
        }else {
            parent->left = nullptr;
            idx++;
            q.push_back(nullptr);
        }
        //assign right child (initialize new node if not null)
        if(vals[idx]){
            TreeNode* right_child = new TreeNode(vals[idx++]);
            parent->right = right_child;
            q.push_back(right_child);
        }else {
            parent->right = nullptr;
            idx++;
            q.push_back(nullptr);
        }       
    }
    return root;
}

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