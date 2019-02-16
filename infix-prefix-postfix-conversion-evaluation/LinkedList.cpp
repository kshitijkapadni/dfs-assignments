/*
 * LinkedList.cpp
 *
 *  Created on: 21-Dec-2018
 *      Author: Kshitij Kapadni
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;
template<class T>
//CONSTRUCTOR
LinkedList<T> ::LinkedList() {
	// INITIALIZING THE HEAD TO NULL
	head = NULL;
}
template<class T>
// INSERT FUNCTION
void LinkedList<T> :: insert_start(T val)
{
	node<T> * temp = getNode(val);
	temp->data = val;
	temp->next= head;
	head = temp;
}
// DELETE FUNCTION
template<class T>
T LinkedList<T> :: delete_start()
{
	node<T> * temp = head;
	head = head->next;
	delete(temp);
}
// CHECK IF LINKED LIST IS EMPTY
template<class T>
bool LinkedList<T>:: isEmpty()
{
	if (head == NULL)
		return true ;
	else
		return false;
}
//DISPLAY FUNCTION OF LINKED LIST
template <class T>
void LinkedList<T> :: display()
{
	node <T> * temp = head;
    if (temp!= NULL)
        //TRAVERSING TILL TEMP IS NOT NULL
        while (temp != NULL)
        {
            cout<<temp->data<<",";
            temp = temp->next;
        }
    else
        cout<<"Empty";
}
// CREATING NEW NODE FOR LINKED LIST
template<class T>
node<T> * LinkedList<T>:: getNode(T)
{
	return new(node<T>);
}
//RETURNING THE HEAD
template<class T>
node<T> * LinkedList<T>:: getHead()
{
	return head;
}
//DESTRUCTOR
template<class T>
LinkedList<T> ::~LinkedList() {
	// TODO Auto-generated destructor stub
	while(!isEmpty())
        delete_start();
}

