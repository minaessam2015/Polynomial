#include<iostream>
#include<vector>
#include "LinkedList.h"
#define nullptr NULL
using namespace std;

LinkedList::LinkedList()
{
        head = nullptr;
		current = nullptr;
		nodeCreator = nullptr;
}

LinkedList::LinkedList(double arr[],int size){
    		head = nullptr;
		current = nullptr;
		nodeCreator = nullptr;

		for (int i = 0; i<size; i++) {
			add_back(arr[i]);
		}
}
LinkedList::LinkedList(std::vector<float>& vec){
	head = nullptr;
		current = nullptr;
		nodeCreator = nullptr;
		for (unsigned int i = 0; i<vec.size(); ++i) {
			add_back(vec[i]);
		}

}

void LinkedList::add_back(float dataIn){

		if (head == nullptr) {
			add_front(dataIn);
			return;
		}
		nodeCreator = new node;
		current->next = nodeCreator;
		nodeCreator->data = dataIn;
		nodeCreator->next = nullptr;
		current = nodeCreator;
}

void LinkedList::add_front(float dataIn){
		nodeCreator = new node;
		if (head == nullptr) {
			head = nodeCreator;
			nodeCreator->data = dataIn;
			nodeCreator->next = nullptr;
			current = head;
			return;
		}

		nodeCreator->next = head;
		nodeCreator->data = dataIn;
		head = nodeCreator;

}

bool LinkedList::add(int position,double dataIn){
		node* tmp = head;
		node* prev = head;
		int pos = 0;
		while (tmp != nullptr) {


			if (pos == position) {
				nodeCreator = new node;
				nodeCreator->data = dataIn;
				nodeCreator->next = tmp;
				prev->next = nodeCreator;
				prev = nullptr;
				tmp = nullptr;
				delete tmp;
				delete prev;

				return true;
			}
			pos++;
			prev = tmp;
			tmp = tmp->next;

		}
		prev = nullptr;
		tmp = nullptr;
		delete tmp;
		delete prev;
		return false;
}

bool LinkedList::isEmpty(){
		if (head == nullptr) return true;

		return false;
}

float LinkedList::get(int position){
		int pos = 0;
		node* tmp = head;
		while (tmp != nullptr) {

			if (pos == position) {
				return tmp->data;
			}
			pos++;
			tmp = tmp->next;
		}
		tmp = nullptr;
		delete tmp;
}

	/*searches for a given data in a list and returns its position
	if no match found returns -1*/
int LinkedList::get(double dataIn) {
		int pos = 0;
		node* tmp = head;
		while (tmp != nullptr) {
			pos++;
			if (tmp->data == dataIn) {
				return pos;
			}
			tmp = tmp->next;
		}
		delete tmp;
		return -1;
	}
/*get the average value of a linked list data */
double LinkedList::get_average() {
		double sum = 0;
		int size=0;
		node* tmp = head;
		while (tmp!=nullptr)
		{
			size++;
			sum += tmp->data;
			tmp = tmp->next;
		}
		if (size == 0) {
			cerr<<"Empty Linked List \n";
		}
		delete tmp;
		return (double)sum / size;

	}

/*reverses a linked list*/
void LinkedList::reverse() {
		vector<float> v;
		node* tmp = head;
		while (tmp != nullptr)
		{
			v.push_back(tmp->data);
			tmp = tmp->next;
		}
		tmp = head;
		for ( int i = (v.size() - 1); i >= 0; --i) {
			tmp->data = v[i];
			tmp = tmp->next;
		}
		delete tmp;
	}

void LinkedList::remove_first(){
		if (head == nullptr) {
			return;
		}
		node* tmp = head;
		head = head->next;
		tmp = nullptr;
		delete tmp;
		return;
}
void LinkedList::remove_last(){
    if (head == nullptr) return;
		if (head->next == nullptr) {
			remove_first();
			return;
		}
		node* tmp = head;
		while (tmp->next != current) {
			tmp = tmp->next;
		}
		current = tmp;
		tmp = tmp->next;
		current->next = nullptr;
		tmp = nullptr;
		delete tmp;
		}
void LinkedList::print(){
		node* tmp = head;
		while (tmp != nullptr) {
			cout << tmp->data << "  ";
			tmp = tmp->next;
		}
		cout << "\n";
		tmp = nullptr;
		delete tmp;
}
unsigned int LinkedList::size(){

		unsigned int sizee = 0;
		node* tmp = head;
		while (tmp != nullptr) {
			sizee++;
			tmp = tmp->next;
		}
		tmp = nullptr;
		delete tmp;
		return sizee;
		}

void LinkedList::remove_all(){
 node* tmp=head;
 while(tmp!=nullptr){
    node* remo=tmp;
    tmp=tmp->next;
    remo=nullptr;
    delete remo;
 }
}
LinkedList::~LinkedList()
{
    remove_all();
}
