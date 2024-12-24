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
void listCourses(int stuindex);
int listChoicesForStu();
void viewCourse(int stuIndex);



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
	Course course1 ={"Prog 1","CS111", "Dr.Samy",   {001, 002, 005, 004},4};
	Course course2 ={"Prog 2","CS112", "Dr.Morad",  {001, 002, 003, 005}, 4};
	Course course3 ={"Math 1","CS123", "Dr.Ashraf", {005, 002, 003, 004}, 4};
	Course course4 ={"Math 2","CS333", "Dr.Hani",   {001, 002, 003, 005}, 4};
	Course course5 ={"Prog 3","CS136", "Dr.Sayed",  {001, 002, 003, 005}, 4};
	Course course6 ={"Stat 1","CS240", "Dr.Hussien",{001, 002, 005, 004}, 4};
	Course course7 ={"Stat 2","CS350", "Dr.Morad",  {001, 002, 3000, 4000}, 4};

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

	//array of Assignments
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


//		Student student1 ={"Hussien Samy", 001, 6, {"CS111", "CS112", "CS333", "CS136", "CS240","CS350"}};
//		Student student2 ={"Ashraf Sayed", 002, 7, {"CS111", "CS112", "CS333", "CS136", "CS240","CS350", "CS123"}};
//		Student student3 ={"Mostafa Hussien", 003, 4, {"CS112", "CS123", "CS333", "CS136" }};
//		Student student4 ={"Ali Mohamed", 004, 6, {"CS111", "CS112", "CS333", "CS136","CS123","CS350"}};
//		Student student5 ={"Hani Sayed", 005, 6, {"CS111", "CS112", "CS333", "CS136","CS123","CS240"}};



	//array of courses
	Course courses[7] = {course1, course2, course3, course4, course5, course6, course7};

	//array of doctors
	Doctor doctors[9] = {doctor1, doctor2, doctor3, doctor4, doctor5, doctor6, doctor7, doctor8, doctor9};

	//array of students
	Student students[5] = {student1, student2,student3, student4, student5};





int main()
{


	int stuIndex = firstPage();
	viewCourse(stuIndex);











	return 0;
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



int listChoicesForStu()
{
	int choice;

	cout<<"Please make a choice: \n"
			"\t1. Register in course\n"
			"\t2. List my courses\n"
			"\t3. view course\n"
			"\t4. Grades Report\n"
			"\t5. log out\n";

	cin>>choice;

	return choice;
}

void registerCourse(int stuNum)
{
	cout<<"My courses list: \n";

}

void listCourses(int stuIndex)
{
	cout<<"My Courses List: \n";

	for(int i = 0; i < students[stuIndex].nOfCourses; ++i)
	{
		cout<<i+1<<") "<<students[stuIndex].courses[i].name<<" - "<<students[stuIndex].courses[i].code<<"\n";
	}
}

void viewCourse(int stuIndex)
{
	int choice;

	listCourses(stuIndex);


	cout<<"Which ith [1"<<" - "<<students[stuIndex].nOfCourses<<"] course to view?\n";
	cin>>choice;

	//display course's data
	cout<<"course "<<students[stuIndex].courses[choice-1].name
		<<" with code "<<students[stuIndex].courses[choice-1].code
		<<" taught by "<<students[stuIndex].courses[choice-1].instructor<<"\n";

	// display number of assignments
	cout<< "Course has "<<students[stuIndex].courses[choice-1].nOfAssignments<< " assignments\n";

	for(int i = 0; i <  courses[choice-1].nOfAssignments; ++i)
		{
			if (arr[stuIndex][choice-1][i][0] == 1)
				cout<<"submitted\t";
			else
				cout<<"Not submitted\t";


			cout<< arr[stuIndex][choice-1][i][1]<<"\n";

		}
	}




















//void viweCourse(int stuIndex)
//{
//	int choice;
//
//	listCourses(stuIndex);
//
//	cout<<"Which ith [1"<<" - "<<students[stuIndex].nOfCourses<<"] course to view?\n";
//	cin>>choice;
//
//	for(int i  = 0; i < students[stuIndex].nOfCourses; ++i)
//	{
//		for(int j = 0; j < 7; ++j)
//		{
//			if(students[i].courses[i] == courses[j].code)
//			{
//				cout<<
//			}
//		}
//
//
//	}
//
//}































