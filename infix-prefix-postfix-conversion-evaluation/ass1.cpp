//============================================================================
// Roll No.: 23345          Batch : G11             Class : SEIT 11
// Name : Kshitij Kapadni
// Assignment No.: 01
// Problem Statement : Implement stack as an ADT using Linked List and use this
//                     ADT for conversion of infix expression to postfix,prefix
//                     And evaluation of postfix/prefix expression.
//============================================================================
// HEADER FILES
#include <iostream>
#include <math.h>
#include "StackAdt.h"
#include "StackAdt.cpp"
using namespace std;
// EXPRESSION CLASS
class Expression
{
	char input[50],output[50];
	public:
	    // FUNCTION PROTOTYPES
		void getExp();
        int validateExp();
        int validateExpForEval();
		void in2post();
		void in2pre();
		void postfixEvaluation();
		void prefixEvaluation();
		int PerformOperation(char, int, int);
		void display();
		int priority(char );
		int associativity(char );
}; //END OF EXPRESSION CLASS

//FUNCTION TO CHECK THE ASSOCIATIVITY OF OPERATOR
int Expression :: associativity(char ch)
{
	 if(ch=='+'|| ch=='-' || ch == '*' ||ch =='/' || ch=='%')
		 return 1; //Lto R
    return 2 ;//r to l
}
//FUNCTION TO VALIDATE INFIX EXPRESSION
int Expression :: validateExp()
{
    int i=0,flag=0;
    while(input[i+1]!='\0')
    {   // CHECK IF THERE ARE TWO CONSECUTIVE OPERATORS
        if((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i]== '^'||input[i]== '%')&&(input[i+1] == '+' || input[i+1] == '-' || input[i+1] == '*' || input[i+1] == '/' || input[i+1]== '^'||input[i+1]== '%'))
        {
            cout<<"\n Invalid Expression !! Try Again...";
            return false;
        }
        // CHECK IF THERE ARE TWO CONSECUTIVE OPERANDS
        else if (isalnum(input[i])==isalnum(input[i+1]))
        {
            if ((input[i]>='0'&&input[i]<='9')&&(input[i+1]>='0'&&input[i+1]<='9'))
                flag = 1;
            else
            {
                cout<<"\n Invalid Expression !! Try Again...";
                return false;
            }
        }
        // CHECK IF THERE ARE TWO CONSECUTIVE BRACKETS OF OPPOSITE SIDES
        else if (input[i]==')' && input[i+1]=='(')
        {
            cout<<"\n Invalid Expression !! Try Again...";
            return false;
        }
        else
            flag = 1;
        i++;
    }
    if(flag==1)
        return true;
   // return false;
}

int Expression :: validateExpForEval()
{
    int i=0,oprandCount=0,operatorCount=0;

    while(input[i]!='\0')
    {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i]== '^'||input[i]== '%')
            operatorCount++;
        else if (isalnum(input[i]))
            oprandCount++;
        i++;
    }
    if (oprandCount-1==operatorCount)
        return false;
    cout<<"\n Invalid Expression !! Try Again...";
    return true;
}

//FUNCTION TO GET INPUT EXPRESSION FROM USER
void Expression::getExp()
{
	cout<<"\n Enter Expression : - ";
	cin>>input;
}

//FUNCTION TO CHECK THE PRIORITY OF THE OPERATOR
int Expression::priority(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 2;
			break;
		case '^' :
			return 5;
			break;
		case '/':
		case '*':
		case '%':
			return 3;
            break;
	}
	return 0;

}
//FUNCTION FOR INFIX TO POSTFIX CONVERSION
void Expression::in2post()
{
	int i = 0,k=0;
	StackAdt <char> s;//STACK OBJECT
    do
        getExp();
    while(!validateExp());
	cout<<"****************************************************************";
	cout<<"\n\t Character \t Stack \t\t Output \n";
    cout<<"****************************************************************\n";
    //EXECUTION OF WHILE LOOP UNTILL INPUT EXPRESSION IS NOT NULL
	while(input[i]!= '\0' )
	{
	    //CHECK IF INPUT CHARACTER IS OPERATOR
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i]== '^'||input[i]== '%')
        {
            if(!s.isEmpty())
                if (priority(s.peep())> priority(input[i]))
                    // WHILE LOOP UNTIL STACK IS NOT EMPTY AND TOP OF STACK IS NOT ')'
                    // AND PRIORITY OF OPERATOR IN STACK IS GREATER THEN INPUT OPERATOR
                    // POP THE ELEMENTS OF STACK TO OUPUT VARIABLE
                    while(!s.isEmpty()&&s.peep()!=')' && priority(s.peep())>= priority(input[i]))
                    {
                        output[k++]=s.peep();
                        s.pop();
                    }
                else if(priority (s.peep())== priority(input[i]) )
                        // prority is equal
                        if(associativity(input[i])==1) // L  to R
                         {
                             output[k++]=s.peep();
                             s.pop();
                         }
            s.push(input[i]);
        }
        //CHECK IF INPUT CHARACTER IS OPERAND
        else if((input[i] >= '0' && input[i] <= '9')||(input[i] >= 'a' && input[i] <= 'z')||(input[i] >= 'A' && input[i] <= 'Z'))
            output[k++]=input[i];
        //CHECK IF INPUT CHARACTER IS '('
        else if(input[i]=='(')
            s.push(input[i]);
        //CHECK IF INPUT CHARACTER IS ')'
        // IF YES POP THE ELEMENTS TILL '('
        else if(input[i]==')')
        {
            while(!s.isEmpty()&&s.peep()!='(')
            {
                output[k++]=s.peep();
                s.pop();
            }
            s.pop();
        }
        output[k]='\0';
        cout<<"\t "<<input[i]<<"\t\t ";
        s.display();
        cout<<"\t\t "<<output<<"\n";
		i++; // next token
	 } //end while
    //CHECK IF STACK  NOT EMPTY
	if(!s.isEmpty())
	    //IF NO THEN WHILE LOOP UNTIL ATCK IS EMPTY
		 while(!(s.isEmpty()))
		 {
				 output[k++]=s.peep();
				 s.pop();
		 }
    output[k]='\0';//ADDING NULL AT THE END OF OUTPUT EXPRESSION
    cout<<"\t "<<"Empty"<<"\t\t ";
    s.display();
    cout<<"\t\t "<<output<<"\n";
}//END OF INFIX TO POSTFIX FUNCTION

//FUNCTION FOR  INFIX TO PREFIX CONVERSION
void Expression::in2pre()
{
	int i = 0,k=0,temp;
	StackAdt <char> s;
	do
        getExp();
    while(!validateExp());
    cout<<"****************************************************************";
	cout<<"\n\t Character \t Stack \t\t Output \n";
    cout<<"****************************************************************\n";
	//WHILE LOOP FOR COUNTING THE NO OF CHARACTERS IN EXPRESSION
	while(input[i+1]!= '\0' )
        i++;

    //WHILE FOR REVERSING THE EXPRESSION
	while (k<i)
	{
	    temp = input[k];
	    input[k]=input[i];
	    input[i]=temp;
		k++;
		i--;
	}
	k=0;i=0;

	//WHILE LOOP UNTIL INPUT IS NOT NULL
    while(input[i]!= '\0' )
	{
	    //CHECK IF INPUT CHARACTER IS OPERATOR
    	if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i]== '^'||input[i]== '%')
		{
		    if(!s.isEmpty())
                if (priority(s.peep())> priority(input[i]))
                    // WHILE LOOP UNTIL STACK IS NOT EMPTY AND TOP OF STACK IS NOT ')'
                    // AND PRIORITY OF OPERATOR IN STACK IS GREATER THEN INPUT OPERATOR
                    // POP THE ELEMENTS OF STACK TO OUPUT VARIABLE
                    while(!s.isEmpty()&&s.peep()!=')' && priority(s.peep())> priority(input[i]))
                    {
                        output[k++]=s.peep();
                        s.pop();
                    }
                else if(priority (s.peep())== priority(input[i]) )
                        // prority is equal
                        if(associativity(input[i])==2) // r  to l
                         {
                             output[k++]=s.peep();
                             s.pop();
                         }
            s.push(input[i]);
		}
		//CHECK IF INPUT CHARACTER IS OPERAND
		else if((input[i] >= '0' && input[i] <= '9')||(input[i] >= 'a' && input[i] <= 'z')||(input[i] >= 'A' && input[i] <= 'Z'))
			output[k++]=input[i];
		////CHECK IF INPUT CHARACTER IS ')'
		else if(input[i]==')')
			s.push(input[i]);
		//CHECK IF INPUT CHARACTER IS '('
        // IF YES THE POP FROM STACK TILL ')'
		else if(input[i]=='(')
		{
			while(!s.isEmpty()&&s.peep()!=')')
			{
				output[k++]=s.peep();
				s.pop();
			}
			s.pop();
		}
        output[k]='\0';
        cout<<"\t "<<input[i]<<"\t\t ";
        s.display();
        cout<<"\t\t "<<output<<"\n";

		i++; // next token
	 } //end while

    //CHECK IF STACK IS EMPTY
	if(!s.isEmpty())
	    //POP TILL STACK IS NOT EMPTY
		 while(!s.isEmpty())
         {
				 output[k++]=s.peep();
				 s.pop();
         }
    output[k--]='\0';
    cout<<"\t "<<"Empty"<<"\t\t ";
    s.display();
    cout<<"\t\t "<<output<<"\n";
    i=0;
    //REVERSING AGAIN TO OBTAIN PREFIX EXPRESSION
    while (i<k)
    {
        temp = output[k];
        output[k]=output[i];
        output[i]=temp;
        k--;
        i++;
    }
}//END OF PREFIX CONVERSION

//BEGIN OF POSTFIX EVALUATION
void Expression::postfixEvaluation()
{
    int i=0;
    StackAdt <int> s;
    do
        getExp();
    while(validateExpForEval());
    while (input[i]!='\0')
    {
        //CHECK IF OPERATOR
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i]== '^'||input[i]== '%')
        {
           // Pop two operands.
			int operand2 = s.peep();
            s.pop();
			int operand1 = s.peep();
            s.pop();
			// Perform operation
			int result = PerformOperation(input[i], operand1, operand2);
			//Push back result of operation on stack.
			s.push(result);
        }
        //CHECK IF OPERANDS
        else if(input[i] >= '0' && input[i] <= '9')
        {
            int operand = 0;
			while(input[i]!='\0' && input[i] >= '0' && input[i] <= '9')
            {
				operand = input[i]-'0';
				s.push(operand);
				i++;
			}
            i--;

        }
        //CHECK IF OPERANDS
        else if ((input[i] >= 'a' && input[i] <= 'z')||(input[i] >= 'A' && input[i] <= 'Z'))
        {
            int operand = 0;
            cout<<" Enter the  value of "<<input[i]<<":";
            cin>>operand;
            s.push(operand);
        }
        i++;
    }//END WHILE
    cout<<" Answer is : "<<s.peep();
    s.pop();
}// END OF POSTFIXEVALUATION FUNCTIOM

//FUNCTION FOR PREFIX EVALUATION
void Expression::prefixEvaluation()
{
    int i=0,k=0,temp;
    StackAdt <int> s;
    //GET PREFIX EXPRESSION FROM USER
    do
        getExp();
    while(validateExpForEval());
    //WHILE INPUT NOT NULL
    while(input[i+1]!= '\0' )
    {
        i++;
    }
    //LOGIC FOR REVERSING THE INPUT EXPRESSION
	while (k<i)
	{
	    temp = input[k];
	    input[k]=input[i];
	    input[i]=temp;
		k++;
		i--;
	}
	i=0;
	//WHILE INPUT NOT NULL
    while (input[i]!='\0')
    {
        //CHECK IF OPERATOR
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i]== '^'||input[i]== '%')
        {
           // Pop two operands.
			int operand1 = s.peep();
            s.pop();
			int operand2 = s.peep();
            s.pop();
			// Perform operation
			int result = PerformOperation(input[i], operand1, operand2);
			//Push back result of operation on stack.
			s.push(result);
        }
        //CHECK IF OPERANDS
        else if(input[i] >= '0' && input[i] <= '9')
        {
            int operand = 0;
			while(input[i]!='\0' && input[i] >= '0' && input[i] <= '9')
            {
				operand = input[i]-'0';
				s.push(operand);
				i++;
			}
            i--;
        }
        //CHECK IF OPERANDS
        else if ((input[i] >= 'a' && input[i] <= 'z')||(input[i] >= 'A' && input[i] <= 'Z'))
        {
            int operand = 0;
            cout<<"Enter the  value of "<<input[i]<<":";
            cin>>operand;
            s.push(operand);
        }
        i++;
    }
    cout<<"Answer is : "<<s.peep();
    s.pop();
}

//FUNCTION TO RETURN THE RESULT OF OPERATION
int Expression::PerformOperation(char operation, int operand1, int operand2)
{
    //TO SELECT OPERATION
    switch(operation)
    {
        case '+': return (operand1 + operand2);
        case '-': return (operand1 - operand2);
        case '*': return (operand1 * operand2);
        case '/': return (operand1 / operand2);
        case '^': return (pow(operand1,operand2));
        case '%': return (operand1 % operand2);
        default:
            cout<<"unexpected error!! TRY AGAIN...";
        return -1;
    }

}
// function to display the output of prefix and postfix conversion
void Expression::display()
{
	cout<<"\n Output Expression is :  "<<output;
}
int main()
{
	Expression e1;

	int ch ;
	do
	{
		//MENU
		cout<<"\n 1. Infix to postfix \n 2. Infix To prefix \n 3. Postfix Evaluation \n 4. Prefix Evaluation \n 5. Exit \n Enter your choice :- ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				//infix to postfix
				e1.in2post();
				e1.display();
				break;
			case 2:
				//infix to pretfix
				e1.in2pre();
				e1.display();
				break;
            case 3:
                //postfix evaluation
                e1.postfixEvaluation();
                break;
            case 4:
                //prefix evaluation
                e1.prefixEvaluation();
                break;
			case 5:
				//exit
				return 0 ;
			default :
				//invalid choice
				cout<<"\n Inavlid Choice !! Try Again...";
				break;
		}
	}while(1);
	return 0;
}
