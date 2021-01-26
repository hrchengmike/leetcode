#include "bst.h"
#include <iostream>
#include <deque>
using namespace std;
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


//insert a node to the current BST 
//return true if success
bool insert_node( TreeNode* root, int key){
    TreeNode* cur = root;
    while (true){
        if (key < cur->val){
            if (cur->left == nullptr){
                TreeNode* node = new TreeNode(key);
                cur -> left = node;
                return true;
            }
            cur = cur->left;
        } else if (key > cur->val){
            if (cur->right == nullptr){
                TreeNode* node = new TreeNode(key);
                cur -> right = node;
                return true;
            }
            cur = cur->right;
        } else {
            cout << "The key value is already in the tree!\n";
            return false;
        }
    }
}

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