#include<iostream>
using namespace std;

void printMenu();
void calculateAggregate(string name ,float matricMarks, float interMarks, float ecatMarks);
void compareMarks(string nameStd1, float ecatMarksStd1, string nameStd2, float ecatMarksStd2);
// This program calculates the aggregate of two students and decides which student should be assigned the roll no. 

main()

{

//Variable declaration

	float matricMarks1;
	float interMarks1;
	float ecatMarks1;
	float matricMarks2;
	float interMarks2;
	float ecatMarks2;
	string name1, name2;

	system("cls");            //clear screen
	printMenu();              //function call to print header.

	//Taking input... student 1

	cout <<"Enter first student's information:"<<endl<<endl;

	cout<< "Enter your name: ";
	cin >>name1;

	cout << "Enter your matric marks: ";
	cin >>matricMarks1;

	cout <<"Enter your inter marks: ";
	cin>>interMarks1;

	cout <<"Enter your Ecat marks: ";
	cin >>ecatMarks1;


calculateAggregate(name1, matricMarks1, interMarks1, ecatMarks1);    //function call to calculate aggregate of student 1

	cout <<endl<<endl;

//Taking input... student 2

	cout <<"Enter second student's information:"<<endl<<endl;

	cout<< "Enter your name: ";
	cin >>name2;

	cout << "Enter your matric marks: ";
	cin >>matricMarks2;

	cout <<"Enter your inter marks: ";
	cin>>interMarks2;

	cout <<"Enter your Ecat marks: ";
	cin >>ecatMarks2;

	calculateAggregate(name2, matricMarks2, interMarks2, ecatMarks2); 	//function call to calculate aggreagte of student 2

	compareMarks(name1, ecatMarks1, name2, ecatMarks2);		//function call to compare marks and assign roll number.
}

void printMenu()	//This function is created prints the header of the program. 
{

cout <<endl; 
cout <<"                               #   # #     # ### #       # #### ####  #### ### ##### #   #    #### ####  #         # ### #### #### ### #### #     #  "<<endl;
cout <<"                               #   # #   # #  #   #     #  #    #   # #     #    #    # #     #  # #   # # #     # #  #  #    #     #  #  # # #   #"<<endl;
cout <<"                               #   # #  #  #  #    #   #   #### ####  ####  #    #     #      #### #   # #  #   #  #  #  #### ####  #  #  # #  #  #"<<endl;
cout <<"                               #   # # #   #  #     # #    #    # #      #  #    #     #      #  # #   # #   # #   #  #     #    #  #  #  # #   # #" <<endl;
cout <<"                                ###  #     # ###     #     #### #  #  #### ###   #     #      #  # ####  #    #    # ### #### #### ### #### #     #"<<endl <<endl;



cout <<"                                 #         # #### #     # ####  #### #### #         # #### #     # #####   #### #   # #### ##### #### #         #  "<<endl;
cout <<"                                 # #     # # #  # # #   # #  # #     #    # #     # # #    # #   #   #     #     # #  #      #   #    # #     # #"<<endl;
cout <<"                                 #  #   #  # #### #  #  # #### #  ## #### #  #   #  # #### #  #  #   #     ####   #   ####   #   #### #  #   #  #"<<endl;
cout <<"                                 #   # #   # #  # #   # # #  # #   # #    #   # #   # #    #   # #   #        #   #      #   #   #    #   # #   #" <<endl;
cout <<"                                 #    #    # #  # #     # #  #  #### #### #    #    # #### #     #   #     ####   #   ####   #   #### #    #    # "<<endl <<endl;


}

void calculateAggregate(string name ,float matricMarks, float interMarks, float ecatMarks)	// This funtion calculates the aggregates of the students.
{
	float aggregate;
	
	aggregate=(matricMarks/1100*30)+(interMarks/1100*30)+(ecatMarks/400*40);
	
	cout <<"The aggregate of " << name <<" is: "<< aggregate<<endl;
}


void compareMarks(string nameStd1, float ecatMarksStd1, string nameStd2, float ecatMarksStd2)
{

//This function compares marks and decide the roll no 1.

// Decision making using if statement
	if(ecatMarksStd1>ecatMarksStd2)
	{
	cout <<"Roll no 1 is assigned to student named: "<<nameStd1;
	}
	
	if(ecatMarksStd1<ecatMarksStd2)
	{
		cout <<"Roll no 1 is assigned to student named: "<<nameStd2;
	}
}