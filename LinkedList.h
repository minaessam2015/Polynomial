#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
class LinkedList {

private:
    struct node {
	float data;
	node* next;
};
	node* head;
	node* current;
	node* nodeCreator;


public:
	LinkedList() ;
	/* this constructor takes array as an argument*/
	LinkedList(double arr[], int size) ;


	LinkedList(std::vector<float>& vec) ;


	~LinkedList();
	/* add new element to the list from the back
	if the list was empty just add the element in the front*/
	void add_back(float dataIn) ;


	bool isEmpty() ;


	void add_front(float dataIn) ;


	/*adds an element in a specific position such that
	add(2) puts the element at the third position (zero based index)
	returns a boolean to indicate whether was successful or not
	*/
	bool add(int position, double dataIn) ;




	unsigned int size() ;


	void print();



	void remove_first();


	void remove_last();


	void remove_all();

	float get(int position) ;


};

#endif // LINKEDLIST_H
