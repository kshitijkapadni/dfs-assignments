/*
 * BNode.h
 *
 *  Created on: 18-Jan-2019
 *      Author: standard
 */

#ifndef BNODE_H_
#define BNODE_H_
// NODE STRUCTURE
struct Node
{
	int data;
	struct Node *LChild,*RChild;
};
//BINARY NODE CLASS
class BNode {
	Node * root; //ROOT OF THE TREE
public:
	BNode();
	//FUNCTION PROTOTYPES
	Node* create(Node *);
	void insert1(int);
	void display();
	void displayPre(Node *);
	void displayIn(Node *);
	void displayPost(Node *);
	int depth(Node *);
	void displayLeafNodes(Node *);
	int countLeafNodes(Node*);
    Node* createCopy(Node*);
	Node * getNode(int);
	Node * getRoot();
	Node * setRoot(Node *);
	virtual ~BNode();
};

#endif /* BNODE_H_ */
