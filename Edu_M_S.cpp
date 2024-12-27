/*
 * Edu_M_S.cpp
 *
 *  Created on: Dec 13, 2024
 *      Author: alyaa-smaan
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

//function declaration
int login();
int signup();
void shutdown();
int firstPage();
void registerCourse(int stuIndex);
void listCourses(int stuindex);
void listChoicesForStu(int stuIndex);
void viewCourse(int stuIndex);
void updateListofCourses(int stuIndex, int choice);
void choicenOptionForViewedCourse(int stuIndex, int choice);
void submitSolution(int stuIndex, int choice);



struct Course
{
	string name;
	string code;
	string instructor;
	int regStudents[4];
	int nOfAssignments;
};

struct Doctor
{
	string name;
	int nOfCourses;
	string code;
};


struct Student
{
	string name;
	int ID;
	int nOfCourses;
	Course courses[7];
};



	//list of courses
	Course course1 ={"Prog 1","CS111", "Dr.Samy",   {001, 002, 005, 004}, 4};
	Course course2 ={"Prog 2","CS112", "Dr.Morad",  {001, 002, 003, 005}, 4};
	Course course3 ={"Math 1","CS123", "Dr.Ashraf", {005, 002, 003, 004}, 4};
	Course course4 ={"Math 2","CS333", "Dr.Hani",   {001, 002, 003, 005}, 4};
	Course course5 ={"Prog 3","CS136", "Dr.Sayed",  {001, 002, 003, 005}, 4};
	Course course6 ={"Stat 1","CS240", "Dr.Hussien",{001, 002, 005, 004}, 4};
	Course course7 ={"Stat 2","CS350", "Dr.Morad",  {001, 002, 006, 007}, 4};

	//list of doctors
	Doctor doctor1 = {"Ali", 0};
	Doctor doctor2 = {"Mostafa", 0};
	Doctor doctor3 = {"Hani", 1, "CS333"};
	Doctor doctor4 = {"Mohamed", 0};
	Doctor doctor5 = {"Ashraf", 1, "CS123"};
	Doctor doctor6 = {"Samy", 1, "CS111"};
	Doctor doctor7 = {"Morad", 2, "CS112 CS350"};
	Doctor doctor8 = {"Sayed", 1, "CS136"};
	Doctor doctor9 = {"Hussien", 1, "CS240"};

	//list of students
	Student student1 ={"Hussien Samy", 001, 6, {course1, course2, course4, course5, course6,course7}};
	Student student2 ={"Ashraf Sayed", 002, 7, {course1, course2, course3, course4, course5, course6,course7}};
	Student student3 ={"Mostafa Hussien", 003, 4, {course2, course3, course4, course5 }};
	Student student4 ={"Ali Mohamed", 004, 6, {course1, course2, course3, course4,course5,course7}};
	Student student5 ={"Ali Mohamed", 005, 6, {course1, course2, course3, course4,course5,course6}};

	//array of Assignments for each student
	//arr[student][course][assignment][state of assignment]
	int arr [5][7][4][2] = {

			//first student
			{

					{
							{1,45}, {0,0}, {1,50},{1,20}	//first course
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},


					{
							{1,20}, {0,0}, {1,20},{1,20}    //course 4
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					}

			},

			//second student
			{
					{
							{1,45}, {0,0}, {1,50},{1,20}	//first course
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					}
			},

			//third student
			{

					{
							{1,1}, {0,0}, {1,1}, {0,0}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					}
			},

			//fourth student

			{
					{
							{1,45}, {0,0}, {1,50},{1,20}	//first course
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					}
			},

			//fifth student
			{
					{
							{1,45}, {0,0}, {1,50},{1,20}	//first course
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					},

					{
							{1,45}, {0,0}, {1,50},{1,20}
					}
			}


	};






	//array of courses
	Course courses[7] = {course1, course2, course3, course4, course5, course6, course7};

	//array of doctors
	Doctor doctors[9] = {doctor1, doctor2, doctor3, doctor4, doctor5, doctor6, doctor7, doctor8, doctor9};

	//array of students
	Student students[5] = {student1, student2,student3, student4, student5};





int main()
{


	int stuIndex = firstPage();
	listChoicesForStu(stuIndex);















	return 0;
}



int firstPage()
{
	int num;
	int stuIndex;
	cout<<"Please make a choice: \n"
				"\t1. login\n"
				"\t2. signup\n"
				"\t3. shutdown\n" ;


	cin>>num;

	if(num == 1)
		stuIndex = login();
	else if(num == 2)
		stuIndex = signup();
	else if(num == 3)
		shutdown();
	else
	{
		cout<<"Please enter number from 1 to 3\n";
		firstPage();
	}
	return stuIndex;
}



int login()
{
	string username;
	string password;
	char c;   //s, d, t
	int n;     //id

	cout<<"Username: ";
	cin>>username;

	istringstream iss(username);
	iss>>c>>n;

	cout<<"Password: ";
	cin>>password;

	cout<<"Welcome "<<students[n-1].name <<". you are logged in\n";

	return n-1;
}


int signup()
{
	string username,password, email;
	int num;
	char c;


	cout<<"Username: ";
	cin>>username;

	istringstream iss(username);
	iss>>c>>num;

	cout<<"Email: ";
	cin>>email;

	cout<<"Password: ";
	cin>>password;

	cout<<"Welcome, "<<students[num-1].name<<" - enjoy learning"<<"\n";

	return num-1;
}

void shutdown()
{
	cout<<"Goodbye, we hope you come again\n";
}





// The first page after login for the student
void listChoicesForStu(int stuIndex)
{
	int choiceFromList;

	cout<<"Please make a choice: \n"
			"\t1. Register in course\n"
			"\t2. List my courses\n"
			"\t3. view course\n"
			"\t4. Grades Report\n"
			"\t5. log out\n";

	cin>>choiceFromList;

	if(choiceFromList == 1)
		registerCourse(stuIndex);
	else if (choiceFromList == 2)
		listCourses(stuIndex);
	else if (choiceFromList == 3)
		viewCourse(stuIndex);

}


//void registerCourse()
//{
//	cout<<"My courses list: \n";
//
//
//}


//List of courses for the student
void listCourses(int stuIndex)
{
	cout<<"My Courses List: \n";

	for(int i = 0; i < students[stuIndex].nOfCourses; ++i)
	{
		cout<<i+1<<") "<<students[stuIndex].courses[i].name<<" - "<<students[stuIndex].courses[i].code<<"\n";
	}
}

//Viewing a course for the student
void viewCourse(int stuIndex)
{
	int choice;

	listCourses(stuIndex);


	cout<<"Which ith [1 - "<<students[stuIndex].nOfCourses<<"] course to view?\n";
	cin>>choice;

	//display course's data
	cout<<"course "<<students[stuIndex].courses[choice-1].name
		<<" with code "<<students[stuIndex].courses[choice-1].code
		<<" taught by "<<students[stuIndex].courses[choice-1].instructor<<"\n\n";

	// display number of assignments
	cout<< "Course has "<<students[stuIndex].courses[choice-1].nOfAssignments<< " assignments\n\n";

	//Display state of assignments
	for(int i = 0; i <  courses[choice-1].nOfAssignments; ++i)
		{
			if (arr[stuIndex][choice-1][i][0] == 1)
				cout<<"submitted\t";
			else
				cout<<"Not submitted\t";


			cout<< arr[stuIndex][choice-1][i][1]<<"\n";   //print the grade of each assignment
		}
	choicenOptionForViewedCourse(stuIndex,choice);
}


//List of choices for viewed course
void choicenOptionForViewedCourse(int stuIndex,int choice)
{
	int choicenOption;
	//Print list of choices related to the viewed course
	cout<<"\n\nPlease make a choice: \n"
			"\t1.UnRegister from Course\n"
			"\t2.Submit Solution\n"
			"\t3.Back\n";

	cin>>choicenOption;

	if(choicenOption == 1)
	{
		cout<<"Unregistered Successfully\n";
		listChoicesForStu(stuIndex);
	}
	else if(choicenOption == 2)
		submitSolution(stuIndex,choice);
	else
		listChoicesForStu(stuIndex);
}


//Display updated list of courses after the student unregister from a course
void updateListofCourses(int stuIndex, int choice)
{
	cout<<"My Courses List: \n";

	for(int i = 0, j = 0; i < students[stuIndex].nOfCourses; ++i, ++j)
	{
		if(i == (choice-1))
		{
			j--;
			continue;    //ignore the unregistered course
		}
		cout<<j+1<<") "<< students[stuIndex].courses[i].name << " - " << students[stuIndex].courses[i].code<<"\n";   //display updated list of courses
	}
}


//Student submit as solution for an assignment
void submitSolution(int stuIndex, int choice)
{
	int choicenAss;
	string solution;

	cout<<"Which ith [ 1 - " << courses[choice - 1].nOfAssignments << " ] assignment to submit?\n";
	cin>>choicenAss;

	//check if assignment submitted or not
	if(arr[stuIndex][choice-1][choicenAss-1][0] == 0)
	{
		cout<<"Enter the solutions (no space)\n";
		cin>>solution;

		//update the state of assignment
		arr[stuIndex][choice-1][choicenAss-1][0] = 1;
		//arr[stuIndex][choice-1][choicenAss-1][1] = ;

		cout<<"\n\n Submitted Successfully\n";
	}
	else
		cout<<"You actually submitted this assignment\n";

	//call the list of choices for viewed course
	choicenOptionForViewedCourse(stuIndex,choice);

}












































