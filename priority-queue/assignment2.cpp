//============================================================================
// Roll No.: 23345          Batch : G11             Class : SEIT 11
// Name : Kshitij Kapadni
// Assignment No.: 02
// Problem Statement : Implement priority queue as ADT using single Linked List
//                     for servicing patients in an hospital with priorities as
//                     1) Serious (Top Priority)
//                     2) Medium Illness (Medium Priority)
//                     3) General (Least Priority)
//============================================================================

#include <iostream>
#include "queueAdt.h"
#include "queueAdt.cpp"
using namespace std;
//STRUCTURE OF DOB
struct DOB
{
	int dd,mm,yy;
};//END OF STRUCTURE DOB
//STRUCTURE OF PATIENT
struct patient
{
	int reg_id,priority;
	char p_fname[30],p_lname[30];
	DOB dob;
	float weight,blood_pressure;
};//END OF STRUCTURE PATIENT
//PATIENT CLASS
class Patient
{
	queueAdt <patient> q;
	patient tmp;
	public:
		//FUNCTION PROTOTYPES
		void getData();
		int validateName(char[]);
		int validateDOB(DOB);
		int validatePriority(int );
		void insertData();
		patient deleteData();
		void display();
};//END OF PATIENT CLASS
//VALIDATE NAME FUNCTION
int Patient::validateName(char str[])
{
	int i=0;
	//WHILE STR NOT NULL CHECK EACH CHARACTER IS ALPHA OR NOT
	while(str[i]!='\0')
	{
		if(!isalpha(str[i]))
		{
			cout<<"\n Invalid Name!! Try Again...";
			return false;
		}
		i++;
	}
	return true;
}//END OF VALIDATE FUNCTION
//VALIDATE DOB FUNCTION
int Patient::validateDOB(DOB dob1)
{
	//VALIDATE DAY
	if(dob1.dd>31||dob1.dd<1)
	{
		cout<<"\n Invalid Day !! Enter valid Day...";
		return false;
	}
	//VALIDATE MONTH
	else if(dob1.mm>12||dob1.mm<1)
	{
		cout<<"\n Invalid Month !! Enter valid Month...";
		return false;
	}
	//VALIDATE YEAR
	else if(dob1.yy<1918||dob1.yy>2018)
	{
		cout<<"\n Invalid Year !! Enter valid Year...";
		return false;
	}
	return true;
}//END OF FUNCTION VALIDATE DOB
// VALIDATE PRIORITY FUNCTION
int Patient::validatePriority(int p)
{

	if (p>3||p<1)
	{
		cout<<"\n Invalid priority !! Enter valid proirity...";
		return false;
	}
	return true;
}//END OF VALIDATE PRIORITY FUNCTION
//FUNCTION TO GET DATA FROM THE USER
void Patient::getData()
{
	cout<<"\n Enter the registration id :- ";
	cin>>tmp.reg_id;
	do
	{
		cout<<"\n Enter the name :- ";
		cin>>tmp.p_fname>>tmp.p_lname;
	}while(!validateName(tmp.p_fname)&&!(validateName(tmp.p_lname))); // VALIDATION OF NAME
	do
	{
		cout<<"\n Enter the dob in dd/mm/yy format : - ";
		cin>>tmp.dob.dd>>tmp.dob.mm>>tmp.dob.yy;
	}while(!validateDOB(tmp.dob)); // VALIDATION OF DOB
	cout<<"\n Enter weight : - ";
	cin>>tmp.weight;
	cout<<"\n Enter blood pressure : - ";
	cin>>tmp.blood_pressure;
	do
	{
		cout<<"\n Enter the priority (1. least 2. medium 3. top):- ";
		cin>>tmp.priority;
	}while(!validatePriority(tmp.priority)); // VALIDATION OF PRIORITY
}//END OF GET DATA FUNCTION
//INSERT DATA FUNCTION
void Patient::insertData()
{
	q.insert(tmp);
}//END OF INSERT DATA FUNCTION
//DELETE DATA FUNCTION
patient Patient::deleteData()
{
	tmp = q.delete_start();
	return tmp;
}//END OF DELETE DATA FUNCTION
//DISPLAY DATA FUNCTION
void Patient::display()
{
	q.display();
}//END OF DISPLAY DATA FUNCTION

//MAIN FUNCTION
int main()
{
	Patient p;
	patient tmp;
	int ch;
	do
	{
		cout<<"\n------ Operations on Data ------";
		cout<<"\n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit \n Enter your choice : -  ";
		cin>>ch;
		// TO SELECT OPTION ACCORDING TO USER CHOICE
		switch(ch)
		{
			case 1:
					//insert
					p.getData();
					p.insertData();
					p.display();
					break;
			case 2:
					//delete
					tmp = p.deleteData();
					cout<<"\n********************************************************************************************************************\n";
					cout<<"\t reg_id \t name \t\t\t dob \t weight \t blood pressure \t\t priority \n";
					cout<<"\n********************************************************************************************************************";
					cout<<"\n\t "<<tmp.reg_id<<"\t "<<tmp.p_fname<<" "<<tmp.p_lname;
					cout<<"\t "<<tmp.dob.dd<<"/"<<tmp.dob.mm<<"/"<<tmp.dob.yy<<"\t";
					cout<<"\t "<<tmp.weight<<"\t "<<tmp.blood_pressure<<"\t\t "<<tmp.priority;
					cout<<"\n Now After deleting :  ";
					p.display();
					break;
			case 3:
					//display
					p.display();
					break;
			case 4:
					//exit
					return 0;
			default:
					//INVALID CHOICE
					cout<<"\nInvalid choice !! Try Again...";
					break;
		}
	}while(1);
	return 0;
}
