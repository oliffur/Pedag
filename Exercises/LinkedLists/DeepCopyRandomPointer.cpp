/* deep copies a linked list where each node
 * contains a random pointer to another node or to
 * null; cannot do a simple copy because we do not know
 * where the pointer may point yet
 *
 * tools: mapping, deep copy
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct node{
	int value;
	node* next;
	node* random;
	node(int value): value(value), next(0), random(0){};
};

// performs a deep copy of the linked list starting at
// head and returns the head of the new linked list
node* deepCopy(node* head){
	if (!head) return nullptr;
	
	unordered_map<node*, node*> nodeMap;
	node* newHead = new node(head->value);

	node* currNodeOldList = head;
	node* currNodeNewList = newHead;
	
	while (true){
		nodeMap.emplace(currNodeOldList, currNodeNewList);
		if (currNodeOldList->next){
			currNodeNewList->next = new node((currNodeOldList->next)->value);
		}
		currNodeNewList = currNodeNewList->next;
		currNodeOldList = currNodeOldList->next;
		if (!currNodeOldList) break;
	}

	currNodeOldList = head;
	currNodeNewList = newHead;

	while(currNodeNewList){
		currNodeNewList->random = nodeMap[currNodeOldList->random];
		currNodeOldList = currNodeOldList->next;
		currNodeNewList = currNodeNewList->next;
	}
	
	return newHead;
}

int main(){
	node one(1);
	node two(2);
	node three(3);
	node four(4);
	node five(5);

	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;

	one.random = &three;
	two.random = &one;
	three.random = &five;
	four.random = 0;
	five.random = &three;
	
	node* head = deepCopy(&one);
	while (head){
		cout << head->value << " " << head << " " << head->random << endl;
		head = head->next;
	}
	
	return 0;
}
