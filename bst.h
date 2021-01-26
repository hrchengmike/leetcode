//bst header file

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* init_tree(int vals [], int length);
bool insert_node( TreeNode* root, int key);
void delete_tree (TreeNode* root);
void print_tree(TreeNode* node);
