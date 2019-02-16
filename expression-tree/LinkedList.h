/*
 * LinkedList.h
 *
 *  Created on: 21-Dec-2018
 *      Author: Kshitij Kapadni
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

template <typename T>
//STRUCTURE OF NODE
struct node
{
	T  data;
	struct node<T> * next;
};
//LINKED LIST CLASS
template <class T>
class LinkedList
{
	node <T> * head ;
public:
	LinkedList();
	//FUNCTION PROTYPES
	void insert_start(T);
	T delete_start();
	bool isEmpty();
	void display();
	node<T>* getNode(T);
	node<T>* getHead();

	virtual ~LinkedList();
};

#endif /* LINKEDLIST_H_ */
