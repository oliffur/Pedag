#include <iostream>

struct ListNode{
	int value;
	ListNode* next;

	ListNode(int value): value(value), next(nullptr){};
	ListNode(int value, ListNode* next): value(value), next(next){};

	void print(){
		ListNode* currNode = this;
		while (currNode){
			std::cout << currNode->value << " ";
			currNode = currNode->next;
		}
		std::cout << std::endl;
	}
};


