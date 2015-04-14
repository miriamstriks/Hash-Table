#include <string> 
using namespace std; 

class ListNode
{
	protected:
		int data;
		ListNode * next;

	public:
		ListNode(){
			data = NULL;
			next = NULL;
		}//default constructor

		ListNode(int d)
		{
			data = d;
			next = NULL;
		}  // constructor

		int getData(){
			return data;
		}

		ListNode* getNext(){
			return next;
		}

		void setNext( ListNode* n){
			next = n;
		}

};  // class ListNode
 

class LinkedList{ 

	protected: 
		ListNode* listHead; 
		ListNode* last;
		int length;

	public: 	
		LinkedList(){
		listHead = new ListNode();
		last = listHead;
		length = 0;
		}// constructor

		ListNode* getHead(){
			return listHead;
		}

		void append(ListNode n){
			last -> setNext(&n);
			last = &n;
			length++;
		}

		void append(int d) {
		ListNode* newNode = new ListNode(d);
		last -> setNext(newNode);
		last = newNode;
		length++;
	} // method append(String)

		void append(int d, ListNode* afterNode){
		ListNode* newNode = new ListNode(d);
		newNode->setNext(afterNode->getNext());
		afterNode->setNext(newNode);
		length++;  
	} // method append(int, ListNode)
};//class LinkedList