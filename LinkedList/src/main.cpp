#include"singleLinkedList.h"
#include<forward_list>

int main() {

	//create list and iterator objects
	Timer t;
	List SLList;
	std::forward_list<Data> fwdList;
	auto it = fwdList.before_begin();
	
	//initialize test variables
	static const int MAX_NODES{ 1000000 }; //change for testing
	int position{ 50000 }; //change for testing


//////////////////////////////////////////////////////
//////////CREATION TEST///////////////////////////////
//////////////////////////////////////////////////////

	t.start("SLList creation test");

	SLList.generateList(MAX_NODES);
	t.stop();

	/*SLList.print();*/  // test function

	//stl forward_list used

	Data fwdData;
	t.start("forward_list creation test");

	for (int i = 0; i < MAX_NODES; ++i) {
		fwdData.id = rand() % MAX_NODES;
		fwdList.push_front(fwdData);
	}

	t.stop();
	std::cout << "\n" << std::endl;

	//print function for testing forward_list

	/*for (it = fwdList.begin(); it != fwdList.end(); ++it) {
		std::cout << it->id << std::endl;
	}*/
		
//////////////////////////////////////////////////////
//////////CREATION TEST END///////////////////////////
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
////////// POSITION INSERTION TEST////////////////////
//////////////////////////////////////////////////////

	Data newData;

// my linked list implementation
	newData.id = rand() % MAX_NODES;

	//std::cout << "new data: " << newData.id << std::endl;  //log the value for testing

	t.start("SLList insertion test");

	SLList.insertAtPosition(position, newData);

	t.stop();

	/*SLList.print();*/

// stl list implementation

	it = fwdList.begin();
	
	t.start("forward list insertion test");

	for (int i = 0; i < position; ++i) {
		++it;
	}

	fwdList.insert_after(it, newData);

	t.stop();
	std::cout << "\n" << std::endl;

	/*for (it = fwdList.begin(); it != fwdList.end(); ++it) {
		std::cout << it->id << std::endl;
	}*/

//////////////////////////////////////////////////////
//////////POSITION INSERTION TEST END/////////////////
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//////////DELETION TEST///////////////////////////////
//////////////////////////////////////////////////////

//SLList 
	t.start("SLList delete last test");

	SLList.deleteLast();

	t.stop();

	/*SLList.print();*/

//forward_list
	t.start("forward list delete last test");

	fwdList.pop_front(); //since the foward list pops and pushes to the
						 //front, this deletes the "last" entered
	
	t.stop();
	std::cout << "\n" << std::endl;

	/*for (it = fwdList.begin(); it != fwdList.end(); ++it) {
		std::cout << it->id << std::endl;
	}
*/

//////////////////////////////////////////////////////
//////////DELETION TEST END///////////////////////////
//////////////////////////////////////////////////////


	std::cin.get();

}