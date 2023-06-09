#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode(int rollno, string name);
	bool search(int rollno, Node** ADITYA, Node** ERSA);
	bool listEmpty();
	bool delNode(int rollno, string name);
	void traverse();
};
void CircularLinkedList::addNode(int rollno, string name) { //write your answer here
	Node* newNode = new Node;			//Allocate memory for new node
	newNode->rollNumber = rollno;		//Assign Value to new node
	newNode->name = name;				//Assign Value to new node

	// Menambah node diawal list
	if (LAST == NULL) {
		newNode->next = LAST->next;	//node baru menunjuk node terakhir
		LAST->next = newNode;	//node terakhir menunjuk node baru
	}

	// Menambah node diantara node lainnya
	Node* ERSA = LAST->next;          //Current pointer menunjuk node pertama
	Node* ADITYA = NULL;
	while (ERSA->next->rollNumber < rollno) {   // B.3 Perulangan
		LAST = ERSA;					 //Previous pointer menujuk node pertama
		ERSA = ERSA->next;		   //Current pointer maju satu node
	};

	// Menambah pada bagian akhir list
	newNode->next = LAST->next;  //C.3 Node pertama ditunjuk oleh Node baru
	LAST->next = newNode;        //C.4 Node sebelum terakhir menunjuk Node terakhir/Node yang baru dibuat
	LAST = newNode;				 //Node yang baru dibuat merupakan Node terakhir	
	
}


bool CircularLinkedList::search(int rollno, Node** ADITYA, Node** ERSA) {
	*ADITYA = LAST->next;
	*ERSA = LAST->next;
	while (*ERSA != LAST) {
		if (rollno == (*ERSA)->rollNumber) {
			return true;
		}
		*ADITYA = *ERSA;
		*ERSA = (*ERSA)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode(int rollno, string name) { //write your answer here
	return 0;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				int nomor;
				string nama;
				cout << "\nEnter the roll number of the student: ";
				cin >> nomor;
				cout << "\nEnter the name of the student: ";
				cin >> nama;
				obj.addNode(nomor, nama);
				break;
			}
			case '2': {
				return 0;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}