/*
 * queueAdt.h
 *
 *  Created on: 11-Jan-2019
 *      Author: standard
 */

#ifndef QUEUEADT_H_
#define QUEUEADT_H_
#include <iostream>

template <typename T>
//NODE DECLARATION FOR QUEUE
struct node
{
	T  data;
	struct node<T> * next;
};//END OF STRUCT

template <class T>
//CLASS QUEUEADF
class queueAdt {
	node <T> * front,*rear;
public:
	queueAdt();
	//FUNCTION PROTOTYPES
	void insert(T);
	T delete_start();
	bool isEmpty();
	int size();
	node<T>* getNode(T);
	virtual ~queueAdt();
};

#endif /* QUEUEADT_H_ */
