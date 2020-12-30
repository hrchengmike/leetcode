#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//insert node in a sorted linked list
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

//insert node at the end of linked list
ListNode* insert_end(ListNode* head, int key){
    //cout << key;
    if(head == nullptr){
        ListNode* new_node = new ListNode(key, nullptr);
        return new_node;
    }
    ListNode* cur = head;
    while(cur->next!=nullptr) cur = cur->next;
    ListNode* new_node = new ListNode(key, nullptr);
    cur -> next = new_node;
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