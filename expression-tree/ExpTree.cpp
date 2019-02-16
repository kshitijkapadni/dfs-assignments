/*
 * ExpTree.cpp
 *
 *  Created on: 29-Jan-2019
 *      Author: Kshitij Kapadni
 */

#include "ExpTree.h"
#include<iostream>
using namespace std;
//CONSTRUCTOR
ExpTree::ExpTree()
{
	root = NULL;
}
//GET NODE FUNCTION
Node * ExpTree::getNode(int val)
{
	Node * temp = new (Node);
	temp->LChild = NULL;
	temp->RChild = NULL;
	temp->data = val;
	return temp;
}
//CREATE FUNCTION
void ExpTree::create()
{
	char input[30];
	int i=0;
	Node *temp;
	cout<<"\n Enter Valid postfix expression : ";
	cin>>input;
	//WHILE INPUT NOT NULL
	while(input[i] != '\0')
	{
	    //CHECK IF OPERAND
		if(isOperand(input[i]))
		{
			temp = getNode(input[i]);
			s.push(temp);
		}
		else //IF OPERATOR
        {
			temp = getNode(input[i]);
			temp->RChild = s.peep();
			s.pop();
			temp->LChild = s.peep();
			s.pop();
			s.push(temp);
		}
		i++;
	}
	root = temp;
}
//CHECK IF OPERAND
int ExpTree::isOperand(char token)
{
	if(isalnum(token))
		return true;
	return false;
}
//DISPLAY FUNCTION RECURSIVE
void ExpTree::display()
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
//PREORDER DISPLAY FUNCTION
void ExpTree::displayPre(Node *temp)
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
void ExpTree::displayIn(Node *temp)
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
void ExpTree::displayPost(Node *temp)
{
    //IF TEMP NOT NULL
    if(temp!=NULL)
    {
        displayPost(temp->LChild);
        displayPost(temp->RChild);
        cout<<temp->data<<" ";
    }
}
//NON RECURSIVE DISPLAY FUNCTION
void ExpTree::display_non()
{
	//PREORDER
	displayPre_non(root);
	//INORDER
	displayIn_non(root);
	//POSTORDER
	displayPost_non(root);
}
// NON RECURSIVE PREORDER DISPLAY FUNCTION
void ExpTree::displayPre_non(Node *temp)
{
    int count = 0,i=0;
    char output[30];
    while(1) //WHILE TRUE
    {
        cout<<"\n Pass "<<++count<<" : ";
        //WHILE TEMP NOT NULL
        while(temp != NULL)
        {
            output[i++] = temp->data;
            if (temp->RChild!=NULL)
                s.push(temp->RChild);
            temp = temp->LChild;
        }
        s.display(); //DIPSPLAY STACK
        temp = s.peep();
        s.pop();
        //IF STACK IS EMPTY
        if(s.isEmpty())
            break;
    }
    cout<<"\n Preorder : "<<output;
}
// NON RECURSIVE INORDER DISPLAY FUNCTION
void ExpTree::displayIn_non(Node *temp)
{
    int count = 0,i=0;
    char output[30];
    while(1)
    {
        //IF TEMP NOT NULL
        cout<<"\n Pass "<<++count<<" : ";
        while(temp != NULL)
        {
            s.push(temp);
            temp = temp->LChild;
        }
        if(s.isEmpty()) //IF STACK WAS EMPTY
            break;
        temp = s.peep();
        s.pop();
        cout<<temp->data<<" ";
        output[i++] = temp->data;
        temp = temp->RChild;
    }
    cout<<"\n Inorder : "<<output;
}
//POSTORDER DISPLAY FUNCTION
void ExpTree::displayPost_non(Node *temp)
{
    StackAdt<Node *> s1;
    s.push(temp);
    int count = 0,i=0;
    while(!s.isEmpty()) //WHILE STCAK NOT EMPTY
    {
        cout<<"\n Pass "<<++count<<" : ";
        s.display();
        temp = s.peep();
        s.pop();
        s1.push(temp);
        if(temp->LChild!=NULL) // IF LCHILD NOT NULL
            s.push(temp->LChild);
        if(temp->RChild!=NULL)  // IF RCHILD NOT NULL
            s.push(temp->RChild);
    }
    while(!s1.isEmpty())  //WHILE STACK NOT EMPTY
    {
        temp = s1.peep();
        s1.pop();
        cout<<temp->data<<" ";
    }
}
//DESTRUCTOR
ExpTree::~ExpTree() {

}

