#include <iostream>
#include <deque>
#include "../bst.h"
using namespace std;

class Solution {
public:
    //bfs search, recording depth of nodes in the queue in a seqarate layer queue
    //when pushing children, push layer+1 to the layer queue 
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        deque<TreeNode*> q;
        deque<int> layer;
        q.push_back(root);
        layer.push_back(1);
        int max_layer = 1;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop_front();
            int cur_layer = layer.front();
            layer.pop_front();
            if(cur_layer > max_layer) max_layer = cur_layer;
            if(cur -> left) {
                q.push_back(cur -> left);
                layer.push_back(cur_layer + 1);
            }
            if(cur -> right) {
                q.push_back(cur -> right);
                layer.push_back(cur_layer + 1);
            }
            
        }
        return max_layer;
    }
    int maxDepth_recursion(TreeNode* root) {
        return root?(max(maxDepth_recursion(root->left),maxDepth_recursion(root->right))+1):0;
    }
};

int main(){
    int v []= {5, 1, 4, 0, 0, 3, 6};
    TreeNode* root = init_tree(v, 7);
    print_tree(root);
    Solution s;
    cout << "max_depth: " << s.maxDepth(root) << endl;
    cout << "max_depth(recursion): " << s.maxDepth_recursion(root) << endl;
}