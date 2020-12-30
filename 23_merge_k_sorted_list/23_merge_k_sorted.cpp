#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insert_node(ListNode* head, int key){
    //initialize new node
    ListNode* new_node = new ListNode(key);
    //empty list
    if(head == nullptr){
        new_node -> next = nullptr;
        return new_node;
    }
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while(cur != nullptr && key > cur -> val){
        prev = cur;
        cur = cur->next;
    }
    //insert at first
    if(prev == nullptr) {
        new_node -> next = head;
        return new_node;
    }
    //insert at the middle or last
    prev -> next = new_node;
    new_node -> next = cur;
    return head;
}

void print_list(ListNode* head){
    ListNode* cur = head;
    cout<<"printing list: ";
    while(cur != nullptr){
        cout << cur->val << " ->";
        cur = cur -> next; 
    }
    cout << " end" << endl;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    }
    void testing(){
        cout << "calling testing\n";
    }
};

int main(){
    Solution s;
    //s.testing();
    int arr [] = {3,1,4, 2, 8, 5};
    ListNode* head = nullptr;
    for (int i = 0; i<sizeof(arr)/sizeof(*arr); i++){
        head = insert_node(head, arr[i]);
    }
    print_list(head);
}