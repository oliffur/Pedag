/* given a linked list, determines whether there is a
 * cycle in the linked list
 * 
 * tools used: fast and slow pointers
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

/*
struct node{
	int value;
	node* next;

	node(int value): value(value), next(0){};
};*/

// returns true if there is a cycle and false otherwise
bool findCycle(ListNode* head){
	
	// if list is empty then it is acyclic
	if (head==0) return false;
	
	// make two pointers, one fast and one slow
	// the fast pointer will move two pointers at a time
	// and the slow pointer will move one
	ListNode* fastptr = head->next;
	ListNode* slowptr = head;

	// loop until the pointers align or we reach the
	// end of the list
	while (true){
		// reached end of list, no cycles
		if (fastptr == 0){
			return false;
		}
		else if (fastptr == slowptr){
			return true;
		}
		fastptr = (fastptr->next)->next;
		slowptr = slowptr->next;
	}
}

int main(){
	ListNode two(2);
	ListNode three(3);
	ListNode four(4);
	ListNode five(5);
	ListNode six(6);

	two.next = &three;
	three.next = &four;
	four.next = &five;
	five.next = &six;
	//six.next = &three;

	cout << findCycle(&two) << endl;
}
