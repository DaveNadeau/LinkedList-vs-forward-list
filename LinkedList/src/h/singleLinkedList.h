#pragma once
#include"Timer.h"
struct Data {
	int id{};
	//any other info
};

struct Node {
	Data info;
	Node *next;
};

class List {
private:
	Node *head, *tail;


public:
	List():head(nullptr), tail(nullptr) {
		
	}

	void createNode(struct Data &newInfo);
	void print();
	void insertHead(Data &newInfo);
	//same as createNode(), done as exercise
	//void insertTail(Data &newInfo);
	void insertAtPosition(int position, Data &newInfo);
	void deleteLast();

	//test functions
	void generateList(int maxNodes);
};

