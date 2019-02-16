//============================================================================
// Name        : Assignment3.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BNode.h"
#include "BNode.cpp"
using namespace std;
//MAIN FUNCTION
int main()
{
    int ch,val;
    Node * root1;
    BNode temp,dup;
    cout<<"\n Creating tree....";
    root1 = temp.create(root1);
    temp.setRoot(root1);
    cout<<"\n Tree is : ";
    temp.displayIn(temp.getRoot());
	do
    {
        //MENU
        cout<<"\n --------MENU-------- \n 1. Insert \n 2. Display \n 3. Depth of Tree \n 4. Display Leaf Nodes \n 5. Count of Leaf Nodes\n 6. Create copy of Tree \n 7.Exit \n Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    //insert
                    cout<<"\n Enter the value : ";
                    cin>> val;
                    temp.insert1(val);
                    cout<<"\n Tree is : ";
                    temp.displayIn(temp.getRoot());
                    break;
            case 2:
                    //display
                    temp.display();
                    break;
            case 3:
                    //Depth
                    val = temp.depth(temp.getRoot());
                    cout<<"\n Depth of tree is : "<<val-1;
                    break;
            case 4:
                    //display leaf nodes
                    cout<<"\n Leaf Nodes are : ";
                    temp.displayLeafNodes(temp.getRoot());
                    break;
            case 5:
                    //count of leaf nodes
                    val = temp.countLeafNodes(temp.getRoot());
                    cout<<"\n Number of leaf nodes are : "<<val;
                    break;
            case 6:
                    //create copy of tree
                    root1 = temp.createCopy(temp.getRoot());
                    cout<<"\n Original tree is : ";
                    temp.displayIn(temp.getRoot());
                    cout<<"\n Copied tree is : ";
                    dup.displayIn(root1);
                    break;
            case 7:
                    //exit
                    return 0;
            default:
                    //invalid Choice
                    cout<<"\n Invalid Choice !! Try Again... ";
                    break;
        }
    }while(1);
	return 0;
}
