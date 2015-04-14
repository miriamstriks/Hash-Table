#include "LinkedList.h"
using namespace std;

class HashTable{
	
	private: (LinkedList*)* ary;
			 int size;

	public:
		HashTable(){
			size = 1;
			ary = new LinkedList*[size];
			ary[0] = new LinkedList();
		}//default constructor

		HashTable(int s){
			size = s;
			ary = new LinkedList*[size];
			for(int i=0; i<size; i++)
				ary[i] = new LinkedList();
		}//constructor

		LinkedList** getTable(){
			return ary;
		}

		void print(){
			LinkedList* list;
			ListNode* walker;
			for(int i=0; i<size; i++){
				list  = ary[i];
				walker = list->getHead();
				cout << "Index " << i << ": " << endl;
				while(walker->getNext()!=NULL){
					cout << walker->getNext()->getData() << ", ";
					walker = walker->getNext();
				}
				cout << endl;
			}
		}//print whole table

		void print(int index){
			LinkedList* list = ary[index];
			ListNode* walker = list->getHead();
			cout << "Index " << index << ": " << endl;
			while(walker->getNext()!=NULL){
				cout << walker->getNext()->getData() << ", ";
				walker = walker->getNext();
			}
			cout << endl;
		}//print single bucket
}
