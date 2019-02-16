//============================================================================

//============================================================================

#include <iostream>
#include "ExpTree.h"
#include "ExpTree.cpp"
using namespace std;
// MAIN FUNCTION
int main()
{
	ExpTree exp;
	int ch;
    // LOOP WHILE TRUE
	do
    {   //MENU
        cout<<"\n 1. Create \n 2. Recursive Traversal \n 3. Non-Recursive Traversal \n Enter Your Choice : ";
        cin>>ch;
        //USER CHOICE
        switch(ch)
        {
            case 1:
                //CREATE EXPRESSION TREE
                exp.create();
            case 2:
                //DIPSLAY TREE RECURSIVE
                exp.display();
                break;
            case 3:
                //DISPLAY TREE NON RECURSIVE
                exp.display_non();
                break;
            default:
                cout<<"\n Invalid choice !! try Again...";
        }
    }while(1);
	return 0;
}

