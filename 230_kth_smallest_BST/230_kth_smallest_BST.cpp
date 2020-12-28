//Definition for a binary tree node.
#include <iostream>
#include <deque>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
    }
};

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

TreeNode* min_node(TreeNode* root){
    TreeNode* cur = root;
    while(cur -> left!= nullptr){
        cur = cur -> left;
    }
    cout << "min_node: "<< cur->val << endl;
    return cur;
}

void find_kth_min(TreeNode* cur, int* count, int* result, bool* finished, int k){
    if(cur -> left != nullptr) find_kth_min(cur -> left, count, result, finished, k);
    if(*finished == true) return;
    if(*count == k){
        *result = cur -> val;
        *finished = true;
        return;
    } else {
        (*count) ++;
    }
    if(cur -> right != nullptr) find_kth_min(cur -> right, count, result, finished, k);   
}

int kth_min(TreeNode* root, int k){
    int* count = new int(1);
    int* result = new int(1000);
    bool* finished = new bool(false);
    find_kth_min(root, count, result, finished, k);
    int kth_min = *result;
    delete count;
    delete result;
    delete finished;
    return kth_min ;
}

int kth_min_iterative(TreeNode* root, int k){
    stack<TreeNode*> stack;
    while(true){
        while(root!=nullptr){
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        if(--k==0) return root->val;
        root = root->right;
    }
}

int main(){
    int keys [] = {5,3,6,2,4,1};
    //int keys [] = {1,2,3,4,5,6};
    //int keys [] = {3,1,4,2};
    TreeNode* root = new TreeNode(keys[0]);
    for (int i = 1; i < sizeof(keys)/sizeof(*keys); i++){
        cout << "insert: " << keys[i] <<endl;
        insert_node(root, keys[i]);
    }
    print_tree(root);
    min_node(root);
    //delete_tree(root);
    for(int i = 1; i <= sizeof(keys)/sizeof(*keys); i++){
        cout << i << " th min is: " << kth_min(root, i) << endl;
        cout << i << " th min (iterative) is: " << kth_min_iterative(root, i) << endl;
    }
    return 0;
}
