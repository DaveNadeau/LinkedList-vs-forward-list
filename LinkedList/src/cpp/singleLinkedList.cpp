#include"singleLinkedList.h"

	void List::createNode(struct Data &newInfo) {
		Node *temp = new Node;
		temp->info = newInfo;
		temp->next = nullptr;

		if (head == nullptr) {
			head = temp;
			tail = temp;
			temp = nullptr;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
}

	void List::print() {
		Node *temp = new Node;
		temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->info.id << std::endl;
			temp = temp->next;
		}
	}

	void List::insertHead(Data &newInfo) {
		Node *temp = new Node;
		temp->info = newInfo;
		temp->next = head;
		head = temp;
	}
	//same as createNode(), done as exercise
	/*void List::insertTail(Data &newInfo) {
		Node *temp = new Node;
		temp->info = newInfo;
		temp->next = nullptr;
		tail->next = temp;
		tail = temp;
	}*/

	//would like to do an insert based on struct Data member (like ID)


	void List::insertAtPosition(int position, Data &newInfo) {
		Node *previous = new Node;
		Node * current = new Node;
		Node* temp = new Node;
		current = head;

		for (int i = 0; i < position; ++i)
		{
			previous = current;
			current = current->next;
		}

		temp->info = newInfo;
		previous->next = temp;
		temp->next = current;
	}

	//last in, first out
	void List::deleteLast()
	{
		Node *previous = new Node;
		Node * current = new Node;
		current = head;

		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = nullptr;
		delete current;
	}
	

	void List::generateList(int maxNodes) {
		Data info;
		for (int i = 0; i < maxNodes; ++i) {
			info.id = rand() % maxNodes;
			createNode(info);
		}
	}