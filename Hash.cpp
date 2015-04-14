//step 0: prepare 
#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"
;using namespace std;

typedef int (*functiontype)(int,int);

int hashOne(int data, int b){
	return data % b;
}

int hashTwo(int data, int b){
	int sumOfDigits = 0;
	while (data > 0) {
		sumOfDigits += data % 10;
		data /= 10;
	}
	return sumOfDigits % b;
}

int hashThree(int data, int b){
	int sumOfAsciis = 0;
	char c;
	while (data > 0) {
		c = '0' + data % 10;
		sumOfAsciis += (int)c;
		data /= 10;
	}
	return sumOfAsciis % b;
}

ListNode* findSpot(LinkedList* list, int data){
	ListNode* walker = list->getHead();
	while(walker->getNext() != NULL && walker->getNext()->getData() <= data)
		if(walker->getNext()->getData() == data)
			return NULL;
		else walker = walker->getNext();
	return walker;
}

void hashThis(ifstream& inFile, HashTable* hashTable, int b, functiontype hashChoice){
	int data, index;
	ListNode* spot;
	//step 1: data <-- get an integer from infile 
	while(inFile >> data){
	
		//step 2: index <-- hashFunction(data, B) 
		index = hashChoice(data,b);

		//step 3: output data and index 
		cout << data << " --> " << index << endl;

		//step 4: spot <-- findSpot(hashTable[index], data) 
		spot = findSpot(hashTable->getTable()[index],data);

		//step 5: if spot == Null, output NO insertion : data already in database, 
		//		else insert new node in between spot and spot's next, 
		//		print linked list (hashTable[index]) 
		if(spot == NULL)
			cout << data << " already in database" << endl;
		else{
			hashTable->getTable()[index]->append(data,spot);
			hashTable->print(index);
		}
	}
}

int main(){
	
	int bsize, hashChoice, data;
	string filename = "";
	ifstream inFile;

	//step 1: Bsize <-- ask user
	cout << "Enter hash table size: ";
	cin >> bsize;
	//clear input buffer
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	//step 2: Dynamically create a hashTable of size Bsize
	HashTable* hashTable = new HashTable(bsize);

	//step 3: infile <-- open file 
	cout << "Enter file name: ";
	getline(cin, filename);
	inFile.open(filename.c_str());

	//step 4: whichHash <-- ask user which hash function to use (choice of 1, 2 and 3) 
	do{
		cout << "Which hash function would you like to use (1, 2, or 3)? ";
		cin >> hashChoice;

		//step 5:	if whichHash == 1 call hashOne (infile, hashTable)
		//		else if whichHash == 2 call hashTwo (infile, hashTable
		//		else if whichHash == 3 call hashThree (infile, hashTable
		//		else repeat step 4 and 5 until get it right 
		switch(hashChoice){
			case 1:
				hashThis(inFile, hashTable, bsize, &hashOne);
				break;
			case 2:
				hashThis(inFile, hashTable, bsize, &hashTwo);
				break;
			case 3:
				hashThis(inFile, hashTable, bsize, &hashThree);
				break;
			default:
				cout << "Please select 1, 2, or 3. " << endl;
		}
	}while(!(hashChoice == 1 || hashChoice == 2 || hashChoice == 3));

	//step 6: print the entire HashTable 
	cout << "	******************	\nWhole hash table:" << endl;
	hashTable->print();
	
	return 0;
}