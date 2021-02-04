#include <iostream>
#include <deque>
#include "../bst.h"
using namespace std;
bool visit(TreeNode* node, int val, deque<TreeNode*>& q){
    if(node == nullptr) return false;
    if(visit(node -> left, val, q)){
        q.push_back(node);
        return true;
    }
    if(visit(node -> right, val, q)){
        q.push_back(node);
        return true;       
    }
    if(node -> val == val){
        q.push_back(node);
        return true;
    }
    return false;
}

void path_to_node(TreeNode* root, TreeNode* node, deque<TreeNode*>& q){
    visit(root, node->val, q);
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> q1;
        deque<TreeNode*> q2;
        path_to_node(root, p, q1);
        path_to_node(root, q, q2);
        TreeNode* cur;
        while(true){
            if(q1.empty() || q2.empty()) break;
            if(q1.back()->val != q2.back()->val) break;
            cur = q1.back();
            q1.pop_back();
            q2.pop_back();
        }
        return cur;
    }
};

int main(){
    Solution s;
    int v []= {3,5,1,6,2,9,8,0,0,7,4};
    /*
         3
        / \
       5   1
      / \ / \
     6  2 9  8
       / \
      7   4 
    */
    TreeNode* root = init_tree(v, 11);
    TreeNode* p = find_node(root, 4);
    TreeNode* q = find_node(root, 6);
    //print_tree(root);
    cout << "lowest common ancester of 6 and 4 is: " << s.lowestCommonAncestor(root, p, q)->val <<endl;
    delete_tree(root);
    return 0;
}