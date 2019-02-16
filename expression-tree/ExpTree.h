/*
 * ExpTree.h
 *
 *  Created on: 29-Jan-2019
 *      Author: Kshitij Kapadni
 */

#ifndef EXPTREE_H_
#define EXPTREE_H_
#include "StackAdt.h"
#include "StackAdt.cpp"
//STRUCTURE NODE
struct Node
{
	char data;
	Node * LChild,*RChild;
};
//CLASS EXPRESSSION TREE
class ExpTree
{
	Node * root;
	StackAdt<Node *> s;
public:
	ExpTree();
	//PROTOTYPE DECLARATION
	Node * getNode(int);
	void create();
	void display();
	void display_non();
	void displayIn(Node *);
	void displayPre(Node *);
	void displayPost(Node *);

	void displayIn_non(Node *);
	void displayPre_non(Node *);
	void displayPost_non(Node *);

	int isOperand(char);
	virtual ~ExpTree();
};

#endif /* EXPTREE_H_ */
