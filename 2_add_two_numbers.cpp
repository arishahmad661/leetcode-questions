#include<iostream>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* result = new ListNode(0);
    ListNode* current = result;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr || carry > 0){
    
        int sum = carry;
        if(l1 != nullptr){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr){
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }
    return result -> next;
}

int main(){
    int arr1[] = {0,1,2,3,43,4,4};
    int arr2[] = {0,1,2,3,43,4,4,6,6,4,4,4};

    ListNode* head1 = new ListNode(0);
    ListNode* current1 = head1;
    ListNode* head2 = new ListNode(0);
    ListNode* current2 = head2;

    for(int i = 1; i < sizeof(arr1)/sizeof(arr1[0]); i++){
        current1->next = new ListNode(arr1[i]);
        current1 = current1->next;
    }
    for(int i = 1; i < sizeof(arr2)/sizeof(arr2[0]); i++){
        current2->next = new ListNode(arr2[i]);
        current2 = current2->next;
    }

    ListNode* result = addTwoNumbers(head1, head2);
    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
}