/*
 * BST.h
 *
 *  Created on: 01-Feb-2019
 *      Author: standard
 */

#ifndef BST_H_
#define BST_H_
struct Node
{
	int  data;
	Node * LChild,*RChild;
};
class BST
{
	Node * root;
public:
	BST();
	void insert(int val);
	Node * create(Node *,int );
	Node * delete_Node(Node *,int);
	Node * findLeftNode(Node *);
	Node* search(Node *,int);
	void mirror(Node * );
	void display();
	void displayPre(Node *);
	void displayIn(Node *);
	void displayPost(Node *);
	void levelOrder(Node*);
	int depth(Node *);
	Node * getNode(int val);
	int getData(Node *);
	void setRoot(Node *);
	Node * getRoot();
	virtual ~BST();
};

#endif /* BST_H_ */
