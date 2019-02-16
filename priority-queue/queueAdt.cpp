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
	if (isEmpty())
	{
		temp->data = val;
		rear = temp;
		front = temp;
	}
	//ELSE NOT EMPTY
	else
	{
		//CHECK IF PRIORITY OF 1ST ELEMENT IN QUEUE IS LESS THAN INPUT PIORITY
		if(front->data.priority<val.priority)
		{
			temp->data = val;
			temp->next = front;
			front = temp;
		}
		// ELSE IT IS GREATER THAN
		else
		{
			tmp = front;
			//WHILE NOT NULL AND QUEUE ELEMENT PIORITY IS GREATER THAN INPUT PIORITY
			while(tmp != NULL && tmp->data.priority>=val.priority)
			{
				prev = tmp;
				tmp = tmp->next;
			}
			temp->data = val;
			temp->next = prev->next;
			prev->next = temp;
		}
	}
}//END OF INPUT FUNCTION
//DELETE DATA FUNCTION
template<class T>
T queueAdt<T> :: delete_start()
{
	node<T> * temp = front;
	T val = front->data;
	front = front->next;
	delete(temp);
	return val;
}//END OF DELETE DATA FUNCTION
//CHECK IF QUEUE IS EMPTY
template<class T>
bool queueAdt<T>:: isEmpty()
{
	if (rear == NULL||front == NULL)
		return true ;
	else
		return false;
}// END OF IS EMPTY FUNCTION
//DISPLAY FUNCTION
template <class T>
void queueAdt<T> :: display()
{
	node <T> * n = front;

	cout<<"\n********************************************************************************************************************";
	cout<<"\n\t reg_id \t name \t\t\t dob \t\t weight \t blood pressure \t priority \n";
	cout<<"\n********************************************************************************************************************";
	//WHILE NOT NULL
	while(n->next!=NULL)
	{
		cout<<"\n\t "<<n->data.reg_id<<"\t\t "<<n->data.p_fname<<" "<<n->data.p_lname;
		cout<<"\t "<<n->data.dob.dd<<"/"<<n->data.dob.mm<<"/"<<n->data.dob.yy<<"\t ";
		cout<<n->data.weight<<"\t\t "<<n->data.blood_pressure<<"\t\t\t "<<n->data.priority;
		n = n->next;
	}

}//END OF DISPLAY FUNCTION
//CREATING NOT FUNCTION
template<class T>
node<T> * queueAdt<T>:: getNode(T)
{
	return new(node<T>);
}//END OF CREATE NODE FUNCTION
//DESTRUCTOR
template<class T>
queueAdt<T>::~queueAdt()
{
}

