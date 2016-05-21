/* given a singly linked list L0 -> L1 -> ... -> Ln
 * reorder it to L0 -> Ln -> L1 -> L(n-1) -> ...
 * 
 * ideas:
 *   break list in middle (fast & slow pointers)
 *   reverse order of second list
 *   merge two lists back together
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;
// returns the node before the middle node from head to the
// end of the list
ListNode* getOneBeforeMiddle(ListNode* head){
	if (!head || !head->next) return head;

	ListNode* fastptr = head->next;
	ListNode* slowptr = head;

	while (fastptr){
		fastptr = fastptr -> next;
		if (!fastptr) return slowptr;
		else{
			fastptr = fastptr -> next;
			slowptr = slowptr -> next;
		}
	}
	return slowptr;
}

void reverseHereToEnd(ListNode* head){
	if (!head) return;
	// storage pointers that point to next and previous nodes
	// so that they don't get lost
	ListNode* nextNode = head->next;
	ListNode* currNode = head;
	ListNode* prevNode = nullptr;

	while (nextNode){
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
		nextNode = currNode->next;
	}
}

void mergeLists(ListNode* one, ListNode* two){
	if (!one) return;
	if (!two) return;
	// keep track of current pointer
	ListNode* oneptr = one;
	ListNode* twoptr = two;

	// keep track of next pointer
	ListNode* onenext = one->next;
	ListNode* twonext = two->next;

	while (twoptr){
		oneptr->next = twoptr;
		twoptr->next = onenext;
		oneptr = onenext;
		twoptr = twonext;
		onenext = onenext->next;
		twonext = twonext->next;
	}
}

// reorders list (main function)
void reorderList(ListNode* head){
	// get one node before the middle node
	ListNode* oneBeforeMiddle = getOneBeforeMiddle(head);
	// save the middle node
	ListNode* middle = oneBeforeMiddle -> next;
	// cut connection to middle
	oneBeforeMiddle->next = nullptr;
	// reverse from middle to end
	reverseHereToEnd(middle);
	// merge the two lists
	mergeLists(head, middle);
}


int main(){
	ListNode ten(10);
	ListNode nine(9, &ten);
	ListNode eight(8, &nine);
	ListNode seven(7, &eight);
	ListNode six(6, &seven);
	ListNode five(5, &six);
	ListNode four(4, &five);
	ListNode three(3, &four);
	ListNode two(2, &three);
	ListNode one(1, &two);

	reorderList(&one);

	one.print();
	return 0;
}
