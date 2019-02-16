/*
 * queueAdt.cpp
 *
 *  Created on: 11-Jan-2019
 *      Author: standard
 */

#include "queueAdt.h"
#include <iostream>
using namespace std;
template<class T>
//CONSTRUCTOR
queueAdt<T>::queueAdt() {
	front = rear = NULL;
}
//INSERT FUNCTION
template<class T>
void queueAdt<T> :: insert(T val)
{
	node<T> * temp = getNode(val),*tmp,*prev;
	//CHECK IF EMPTY
	if(front == NULL && rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = getNode(val);
        rear = rear->next;
    }
}//END OF INPUT FUNCTION
//DELETE DATA FUNCTION
template<class T>
T queueAdt<T> :: delete_start()
{
	node<T> * temp = front;
	T val = front->data;
	front = front->next;
	if (front ==NULL)
        rear = front;
	delete(temp);
	return val;
}//END OF DELETE DATA FUNCTION
//CHECK IF QUEUE IS EMPTY
template<class T>
bool queueAdt<T>:: isEmpty()
{
	if (rear == NULL&&front == NULL)
		return true ;
	else
		return false;
}// END OF IS EMPTY FUNCTION
//DISPLAY FUNCTION
template <class T>
int queueAdt<T> :: size()
{
    int size1=0;
	node <T> * n = front;
	//WHILE NOT NULL
	while(n!=NULL)
	{
	    size1++;
		n = n->next;
	}
    return size1;
}//END OF DISPLAY FUNCTION

//CREATING NODE FUNCTION
template<class T>
node<T> * queueAdt<T>:: getNode(T val)
{
	node<T>*temp =  new(node<T>);
	temp->data = val;
	temp->next = NULL;
	return temp;
}//END OF CREATE NODE FUNCTION
//DESTRUCTOR
template<class T>
queueAdt<T>::~queueAdt() {
}

