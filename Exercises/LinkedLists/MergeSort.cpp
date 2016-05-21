#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

ListNode* findMiddle(ListNode* head);
ListNode* merge(ListNode* head1, ListNode* head2);

ListNode* mergeSort(ListNode* head){
    if (head == nullptr || head->next == nullptr) return head;
    
    ListNode* middle = findMiddle(head);
    ListNode* oneAfterMiddle = middle->next;
    middle->next = nullptr;
    
    ListNode* head1 = mergeSort(head);
	ListNode* head2 = mergeSort(oneAfterMiddle);
    
    return merge(head1,head2);
}

ListNode* merge(ListNode* head1, ListNode* head2){
    // are these even possible?
    if (head1==nullptr) return head2;
    if (head2==nullptr) return head1;
    
    ListNode* head;
    ListNode* prev;
    
    if (head1->value < head2->value){
        head = head1;
        head1 = head1->next;
        head->next = nullptr;
    }
    else{
        head = head2;
        head2 = head2->next;
        head->next = nullptr;
    }
    
    prev = head;
    
    while (head1 != nullptr || head2 != nullptr){
        if (head1 == nullptr){
            prev->next = head2;
            return head;
        }
        if (head2 == nullptr){
            prev->next = head1;
            return head;
        }
        
        if (head1->value < head2->value){
            prev->next = head1;
            head1 = head1->next;
            prev->next->next = nullptr;
        }
        else{
            prev->next = head2;
            head2 = head2->next;
            prev->next->next = nullptr;
        }
        
        return head;
    }
}

ListNode* findMiddle(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast){
        fast = fast->next;
        if (fast) fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
	ListNode three(3);
	ListNode one(1, &three);
	ListNode four(4, &one);
	ListNode five(5, &four);
	ListNode two(2, &five);

	ListNode* head = mergeSort(&two);
			
    head->print();
    return 0;
}
