/*
 * BNode.cpp
 *
 *  Created on: 18-Jan-2019
 *      Author: standard
 */

#include "BNode.h"
#include <iostream>
using namespace std;
//CONSTRUCTOR
BNode::BNode() {
	root = NULL;
}

//GET NODE FUNCTION
Node * BNode::getNode(int val)
{
	Node* tmp = new(Node); // CREATING NEW NODE
	tmp->data = val;
    tmp->LChild = NULL;
    tmp->RChild = NULL;
    return tmp;
}

//FUNCTION TO RETURN ROOT
Node * BNode::getRoot()
{
	return root;
}
//FUNCTIO TO SET ROOT
Node * BNode::setRoot(Node * temp)
{
	root = temp;
}
//FUNCTION TO CREATE BINARY TREE
Node* BNode::create(Node* temp)
{
	int val;
	cout<<"\n Enter the Data(-1 for NULL): ";
	cin>>val;
	//RETURN NULL IF VALUE IS -1
	if(val==-1)
		return NULL;
	temp = getNode(val);
	cout<<"\n Enter Left Child of "<<val;
	temp->LChild = create(temp->LChild);
	cout<<"\n Enter Right Child of "<<val;
	temp->RChild = create(temp->RChild);
	return temp;
}

void BNode::insert1(int val)
{
    //INSERT AT ROOT IF ROOT IS NULL
	if (root == NULL)
		root = getNode(val);
    //ASK USER CHOICE FOR INSERTING AT LEFT OR RIGHT SUBTREE
	else
	{
		Node *temp = root;
		int ch;
        //MENU
        do
        {
            //ASK USER WHETHER TO GO TO LEFT OR RIGHT
            cout<<"\n Current position : "<<temp->data;
            cout<<"\n 1. Left \n 2. right\n Enter Your Choice : ";
            cin>>ch;
            //IF CHOICE IS LEFT
            if (ch == 1)
                //IF LEFT CHILD IS NULL
                if (temp->LChild==NULL)
                {
                    temp->LChild = getNode(val);
                    break;
                }
                //IF LCHILD NOT NULL
                else
                    temp = temp->LChild;
            //IF CHOICE IS RIGHT
            else if(ch == 2)
                //IF RCHILD IS NULL
                if(temp->RChild==NULL)
                {
                    temp->RChild = getNode(val);
                    break;
                }
                //IF RCHILD IS NOT NULL
                else
                temp = temp->RChild;
            else
                cout<<"\n Invalid choice!!Try Again...";
        }while(1);
	}
}
//FUUNCTION FOR DISPLAY
void BNode::display()
{
        int ch ;
        // MENU
        cout<<"\n 1. Preorder \n 2. Inoder \n 3. Postorder \n Enter Your choice : ";
        cin>>ch;
        //SELECTION
        switch(ch)
        {
            case 1:
                //PREORDER
                cout<<"\n Preorder : ";
                displayPre(root);
                break;
            case 2:
                //INORDER
                cout<<"\n Inorder : ";
                displayIn(root);
                break;
            case 3:
                //POSTORDER
                cout<<"\n Postorder : ";
                displayPost(root);
                break;
            default:
                //INVALID CHOICE
                cout<<"\n Invalid Choice !! Try Again...";
                break;
        }
}
//PREORDER DISPLAY FUNCTION
void BNode::displayPre(Node *temp)
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
void BNode::displayIn(Node *temp)
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
void BNode::displayPost(Node *temp)
{
    //IF TEMP NOT NULL
    if(temp!=NULL)
    {
        displayPost(temp->LChild);
        displayPost(temp->RChild);
        cout<<temp->data<<" ";
    }
}
//DEPTH FUNCTION
int BNode::depth(Node *temp)
{
        // IF TEMP IS NULL
        if(temp==NULL)
            return 0;
        return 1+ max(depth(temp->LChild),depth(temp->RChild));
}
//DISPLAY LEAF NODE FUNCTION
void BNode::displayLeafNodes(Node * temp)
{
    //IF TEMP IS NOT NULL
    if (temp!=NULL)
    {
        if(temp->LChild==NULL&& temp->RChild==NULL)
            cout<<temp->data<<" ";
        displayLeafNodes(temp->LChild);
        displayLeafNodes(temp->RChild);
    }
}
//COUNTING LEAF NODE FUNCTION
int BNode::countLeafNodes(Node * temp)
{
    //IF TEMP IS NULL
    if(temp==NULL)
        return 0;
    //IF LCHILD AND RCHILD BOTH ARE NULL
    if (temp->LChild==NULL && temp->RChild==NULL)
        return 1;
    else //IF NOT NULL
        return countLeafNodes(temp->LChild) + countLeafNodes(temp->RChild);
}
//CREATING COPY OF THE TREE
Node* BNode::createCopy(Node * temp)
{
    //IF TEMP IS NULL
	if(temp==NULL)
		return NULL;
    //IF TEMP NOT NULL
	else
	{
			Node * tmp = getNode(temp->data);
			tmp->LChild = createCopy(temp->LChild);
			tmp->RChild = createCopy(temp->RChild);
			return temp;
	}
}
//DESTRUCTOR
BNode::~BNode()
{}

