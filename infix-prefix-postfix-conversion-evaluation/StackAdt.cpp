/*
 * StackAdt.cpp
 *
 *  Created on: 21-Dec-2018
 *      Author: Kshitij Kapadni
 */

#include "StackAdt.h"
//CONSTRUCTOR
template<class T>
StackAdt<T>::StackAdt()
{
}
//PUSH OPERATION
template<class T>
void StackAdt<T>:: push(T val)
{
	l1.insert_start(val);
}
//POP OPERATION
template<class T>
T StackAdt<T>:: pop()
{
	return l1.delete_start();
}
//CHECK IF STACK IS EMPTY
template<class T>
bool StackAdt<T>:: isEmpty()
{
	return l1.isEmpty();
}
//DISPLAY OPERATION
template<class T>
void  StackAdt<T>::display()
{
	l1.display();
}
//CREATING NEW NODE
template<class T>
node<T>* StackAdt<T>:: getNode(T)
{
	return l1.getNode();
}
//TAKING A LOOK AT THE TOP OF THE STACK
template<class T>
T StackAdt<T>:: peep()
{
	return l1.getHead()->data;
}

//DESTRUCTOR
template<class T>
StackAdt<T>::~StackAdt() {
    l1.~LinkedList();
}

