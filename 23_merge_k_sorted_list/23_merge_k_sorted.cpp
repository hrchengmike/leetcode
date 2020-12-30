#include <iostream>
#include <vector>
#include "../singly_linked_list.h"
using namespace std;

//out of place merge
ListNode* merge2lists(ListNode* head1, ListNode* head2){
    ListNode* head = nullptr;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->val < head2-> val){
            head = insert_end(head, head1->val);
            head1 = head1 -> next;
        } else {
            head = insert_end(head, head2->val);
            head2 = head2 -> next;           
        }
    }
    if(head1 == nullptr){
        while(head2 != nullptr) {
            head = insert_end(head, head2->val);
            head2 = head2 -> next;
        }
    } else{
        while(head1 != nullptr) {
            head = insert_end(head, head1->val);
            head1 = head1 -> next;  
        }       
    }
    return head;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];
        vector<ListNode*> temp(lists.begin(), lists.end());
        vector<ListNode*> temp2;
        while(temp.size()>1){
            for(int i = 0; i < temp.size(); i+=2){
                //odd length, and i is at the last element
                if(i == temp.size() -1 ){
                    temp2.push_back(temp[i]);
                    break;
                }
                temp2.push_back(merge2lists(temp[i], temp[i+1]));
            }
            temp.clear();
            for(int i = 0; i< temp2.size(); i++){
                temp.push_back(temp2[i]);
            }
            temp2.clear();
        }
        return temp[0];  
    }

    void testing(){
        cout << "calling testing\n";
    }
};

int main(){
    Solution s;
    //s.testing();
    int arr [] = {1, 5, 8};
    int arr2 [] = {2, 4, 9};
    int arr3[] = {3, 6, 7};
    ListNode* head = nullptr;
    for (int i = 0; i<sizeof(arr)/sizeof(*arr); i++){
        head = insert_node(head, arr[i]);
    }
    ListNode* head2 = nullptr;
    for (int i = 0; i<sizeof(arr2)/sizeof(*arr2); i++){
        head2 = insert_node(head2, arr2[i]);
    }
    ListNode* head3 = nullptr;
    for (int i = 0; i<sizeof(arr3)/sizeof(*arr3); i++){
        head3 = insert_node(head3, arr3[i]);
    }
    print_list(head);
    print_list(head2);
    print_list(head3);
    ListNode* new_head;
    new_head = merge2lists(head, head2);
    print_list(new_head);
    vector<ListNode*> v{head, head2, head3};
    new_head = s.mergeKLists(v);
    print_list(new_head);
}