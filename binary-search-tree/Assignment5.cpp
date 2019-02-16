//============================================================================
// Name        : Assignment5.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BST.h"
#include "queueAdt.h"
#include "BST.cpp"
using namespace std;

int main()
{
	int val,ch;
	BST bst;
	Node * temp = NULL;
	while(1)
	{
		cout<<"\n Enter value (-1 to exit): ";
		cin>>val;
		if(val == -1)
			break;
		temp = bst.create(temp,val);
	}
	bst.setRoot(temp);
	bst.display();
	do
	{
		cout<<"\n 1. Insert \n 2. Delete \n 3. Display \n 4. Search \n 5. Mirror \n 6. Level Order \n 7. height \n 8. Exit \n Enter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				//insert
				cout<<"\n Enter value : ";
				cin>>val;
				bst.insert(val);
				bst.display();
				break;
			case 2:
				//delete
				cout<<"\n Enter value : ";
				cin>>val;
				bst.delete_Node(bst.getRoot(),val);
			case 3:
				//Display
				bst.display();
				break;
			case 4:
				//Search
				cout<<"\n Enter value : ";
				cin>>val;
				temp = NULL;
                temp = bst.search(bst.getRoot(),val);
                if(temp!=NULL)
                    cout<<"\n Value Found";
                else
                    cout<<"\n Value Not Found";
				break;
			case 5:
				//Mirror
				cout<<"\n Original tree is : \n";
				bst.display();
                bst.mirror(bst.getRoot());
				cout<<"\n Mirror of tree is : \n";
				bst.display();
				break;
			case 6:
				//level order

				break;
			case 7:
				//height
				bst.display();
                val = bst.depth(bst.getRoot());
                cout<<"\n Height of the tree is : "<<val;
				break;
			case 8:
				//exit
				return 0;
			default:
				cout<<"\n Invalid Choice !! Try Again...";
		}
	}while(1);
	return 0;
}
