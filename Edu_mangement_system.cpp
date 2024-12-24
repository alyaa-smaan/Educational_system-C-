/*
 * Edu_mangement_system.cpp
 *
 *  Created on: Dec 11, 2024
 *      Author: alyaa-smaan
 */

#include <iostream>
#include <string>

using namespace std;

void login();
void signup();
void firstPage();
void homePageDoc();
void createCourse();
void listCourses();
void viewCourse();
void logOut();

int main()
{

	firstPage();
	homePageDoc();


	return 0;
}

void login()
{
	string email, password;

	cout<<"Enter your Email: ";
	cin>>email;

	getline(cin,password); //dummy to read \n
	cout<<"Enter your password: ";
	getline(cin, password);

}

void signup()
{
	string email, password, firstName, secName, role;

	cout<<"First Name: ";
	cin>>firstName;

	cout<<"second Name: ";
	cin>>secName;

	cout<<"Email: ";
	cin>>email;

	getline(cin,password); //dummy to read \n
	cout<<"Password: ";
	getline(cin,password);

	cout<<"Your Role (Doctor,Student,TA) ";
	cin>>role;

}

void firstPage()
{
	char ans;
	cout<<"Do you have an account? (y,n)";
	cin>>ans;
	if(ans == 'y')
		login();
	else
		signup();
}


//doctor fn.
void homePageDoc()
{
	int num;

	cout<<"1. Create Course\n"
		<<"2. List Courses\n"
		<<"3. View Course\n"
		<<"4. Log Out\n";

	cin>>num;
	if(cin.fail())
	{
		cout<<"Please enter number from 1 to 4\n";
		cin.clear();
		cin.ignore(10000,'\n');   //skip to the next line
	}

	if(num <= 0 || num > 4)
	{
		cout<<"Please enter number from 1 to 4\n";
	}

	else if(num == 1)
		createCourse();
	else if(num == 2)
		listCourses();
	else if(num == 3)
		viewCourse();
	else

		logOut();
}

void createCourse()
{
	int num;

	cout<<"1. upload material\n"
		"2. make a live\n"
		"3. Create Assignment\n"
		"4. Back\n";

	cin>>num;
	if(cin.fail())
	{
		cout<<"Please enter number from 1 to 4\n";
		cin.clear();
		cin.ignore(10000,'\n');   //skip to the next line
	}

	if(num <= 0 || num > 4)
		cout<<"Please enter number from 1 to 4\n";
	else if(num == 1)
		cout<<"uplooooooooood\n";
	else if(num == 2)
		cout<<"start a live\n";
	else if(num == 3)
		cout<<"create ass\n";
	else
		homePageDoc();

}

void listCourses()
{
	cout<<"machine learning\n"
		"operating system\n"
		"computer graphics\n";
}

void viewCourse()
{
	cout<<"1. List Assignments\n"
			"2. View Assignment\n"
			"3. Create Assignment\n"
			"4. Back\n";
}
































//log out
void logOut()
{
	cout<<"Good Bye\n";
	firstPage();

}




