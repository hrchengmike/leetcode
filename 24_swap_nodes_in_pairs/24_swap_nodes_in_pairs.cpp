//Definition for singly-linked list.
#include "../singly_linked_list.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* cur_node = head;
        ListNode* next_node = cur_node -> next;
        ListNode* temp;
        head = head->next;
        while(true){
            temp = next_node -> next;
            next_node -> next = cur_node;
            if(temp == nullptr){
                cur_node -> next = nullptr;
                break;
            } else if (temp -> next == nullptr){
                cur_node -> next = temp;
                break;
            }
            cur_node -> next = temp -> next;
            cur_node = temp;
            next_node = cur_node->next;
        }
        return head;  
    }
};

int main(){
    Solution s;
    //s.testing();
    int arr [] = {1, 2, 3, 4, 5, 6};
    ListNode* head = nullptr;
    for (int i = 0; i<sizeof(arr)/sizeof(*arr); i++){
        head = insert_node(head, arr[i]);
    }   
    print_list(head);
    head = s.swapPairs(head);
    print_list(head);
    return 0;
}