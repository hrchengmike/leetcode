class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return nullptr;
        }
        //Return pointer to middle node, and head of two sublists
        ListNode* head_l;
        ListNode* head_r;
        ListNode* mid;
        ListNode* slow = head;
        ListNode* fast = head;
        //one node
        if(!fast->next){
            head_l = nullptr;
            head_r = nullptr;
            mid = fast;
        //two nodes
        } else if (!fast->next->next){
            head_l = nullptr;
            head_r = fast->next;
            mid = fast;
        } else {  
            ListNode* prev = new ListNode(0, slow);
            while(fast->next && fast->next->next){
                prev = prev->next;
                slow = slow->next;
                fast = fast->next->next;
            }         
            prev->next = nullptr;
            mid = slow;
            head_l = head;
            head_r = slow->next;
        }

        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head_l);
        root->right = sortedListToBST(head_r);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return nullptr;
        }
        if(!head->next){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        //Return pointer to middle node, and head of two sublists
        ListNode* slow = head;
        ListNode* fast = head->next;
        // >= two nodes
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }     
        ListNode* mid = slow->next;
        slow->next = nullptr;   
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};