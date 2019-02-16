/*
 * BST.cpp
 *
 *  Created on: 01-Feb-2019
 *      Author: standard
 */

#include "BST.h"
#include "queueAdt.h"
#include "queueAdt.cpp"
#include<iostream>
using namespace std;
BST::BST()
{
	root = NULL;
}

Node * BST::create(Node * temp,int val)
{
	if(temp == NULL)
			temp = getNode(val);
	else
		if(val<temp->data)
			temp->LChild = create(temp->LChild,val);
		else if(val>temp->data)
			temp->RChild = create(temp->RChild,val);
		else
			cout<<"\n Duplicate Data!! Try Again...";
	return temp;
}

void BST::setRoot(Node * temp)
{
	root = temp;
}

void BST::insert(int val)
{
	if(root == NULL)
		root = getNode(val);
	else
	{
		Node *temp = root,*temp1 = root;
		while(temp1 != NULL && val != temp->data)
		{
			temp = temp1;
			if(val<temp->data)
				temp1=temp->LChild;
			else if(val>temp->data)
				temp1=temp->RChild;
		}
		if(val == temp->data)
			cout<<"\n Duplicate Data!! Try Again...";
		else if(val<temp->data)
			temp->LChild = getNode(val);
		else if(val>temp->data)
			temp->RChild = getNode(val);
	}
}

Node * BST::delete_Node(Node * temp,int val)
{
    if(temp == NULL)
        return temp;
    if(val<temp->data)
        temp->LChild = delete_Node(temp->LChild,val);
    else if(val>temp->data)
        temp->RChild = delete_Node(temp->RChild,val);
    else
    {
        if(temp->LChild==NULL)
        {
            Node * temp1 = root->RChild;
            delete(temp);
            return temp1;
        }
        else if(temp->RChild==NULL)
        {
            Node * temp1 = root->LChild;
            delete(temp);
            return temp1;
        }

        Node * temp1 = findLeftNode(temp->RChild);
        temp->data = temp1->data;
        temp->RChild = delete_Node(temp->RChild,temp->data);
    }
    return temp;
}

Node * BST::findLeftNode(Node * temp)
{
	while (temp->LChild!= NULL)
        temp = temp->LChild;
    return temp;
}
Node * BST::search(Node * temp,int val)
{
    if(temp==NULL||temp->data == val)
        return temp;
    if(temp->data<val)
        return search(temp->RChild,val);
    else if(temp->data>val)
        return search(temp->LChild,val);
    else
        return NULL;
}
int BST::getData(Node * temp)
{
    return temp->data;
}
void BST::mirror(Node * temp)
{
	Node * temp1;
	if(temp != NULL)
	{
		temp1 = temp->LChild;
		temp->LChild = temp->RChild;
		temp->RChild = temp1;
	}
}

Node * BST::getRoot()
{
	return root;
}

//PREORDER DISPLAY FUNCTION
void BST::displayPre(Node *temp)
{
    //IF TEMP NOT NULL
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        displayPre(temp->LChild);
        displayPre(temp->RChild);
    }
}
//INORDER DISPLAY FUNCTION
void BST::displayIn(Node *temp)
{
    //IF TEMP NOT NULL
    if(temp!=NULL)
    {
        displayIn(temp->LChild);
        cout<<temp->data<<" ";
        displayIn(temp->RChild);
    }
}
//POSTORDER DISPLAY FUNCTION
void BST::displayPost(Node *temp)
{
    //IF TEMP NOT NULL
    if(temp!=NULL)
    {
        displayPost(temp->LChild);
        displayPost(temp->RChild);
        cout<<temp->data<<" ";
    }
}

void BST::display()
{
	//PREORDER
	cout<<"\n Preorder : ";
	displayPre(root);
	//INORDER
	cout<<"\n Inorder : ";
	displayIn(root);
	//POSTORDER
	cout<<"\n Postorder : ";
	displayPost(root);
}



void BST::levelOrder(Node* temp)
{
	while(temp != NULL )
	{

	}
}
int BST::depth(Node *temp)
{
    queueAdt<Node*>  q;
    int height=0;
    int nodeCount =0;
    if(temp==NULL)
        return 0;
    q.insert(temp);
    while(!q.isEmpty())
    {
        nodeCount = q.size();

        while(nodeCount--)
        {
            temp = q.delete_start();
            if(temp->LChild)
                q.insert(temp->LChild);
            if(temp->RChild)
                q.insert(temp->RChild);
        }
        height ++;
    }
    return height;
}
Node * BST::getNode(int val)
{
	Node * temp = new Node;
	temp->data = val;
	temp->LChild=NULL;
	temp->RChild=NULL;
	return temp;
}

BST::~BST() {
	// TODO Auto-generated destructor stub
}

