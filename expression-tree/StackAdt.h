/*
 * StackAdt.h
 *
 *  Created on: 21-Dec-2018
 *      Author: Kshitij Kapadni
 */

#ifndef STACKADT_H_
#define STACKADT_H_
#include <iostream>
#include"LinkedList.h"
#include"LinkedList.cpp"

template <class T>
//class stack
class StackAdt
{
	LinkedList<T> l1;
public:
	StackAdt();
	//FUNCTION PROTOTYPES
	void push(T);
	T pop();
	bool isEmpty();
	void display();
	node<T>* getNode(T);
	T peep();
	virtual ~StackAdt();
};

#endif /* STACKADT_H_ */
