//David Park
//Source.cpp
//Semester Project
//Created 5/09/20
#include <iostream>
#include <string>
#include "BSTteacher.h"

using namespace std;

int main()
{
	bool completed;
	string name, subject;
	int option;
	char avail, choice = 'Y';
	BSTteacher tree;

	while (choice == 'Y' || choice == 'y')
	{
		//Menu
		cout << "Please choose an option from the following list: " << endl;
		cout << "1. Look for a substitute teacher depending on subject" << endl;
		cout << "2. Add new substitute teacher" << endl;
		cout << "3. Display all substitute teachers" << endl;

		cin >> option;

		//make sure user puts in an int
		while (!cin)
		{
			cout << "You have not chosen an integer. Please try again." << endl;
			cin.clear();
			cin.ignore();
			cin >> option;
		}

		//more user validation
		switch (option)
		{
		case 1:
			cout << "Choose a subject: " << endl;
			cout << "1. Math\n2. Science\n3. English\n4. History" << endl;
			cin >> option;
			switch (option)
			{
			case 1:
				tree.searchSubject("Math");
				break;
			case 2:
				tree.searchSubject("Science");
				break;
			case 3:
				tree.searchSubject("English");
				break;
			case 4:
				tree.searchSubject("History");
				break;
			default:
				cout << "Invalde choice." << endl;
				break;
			}
			break;
		case 2:
			cout << "Please type in the following order the teacher's name, subject, and availibility." << endl;
			cin.ignore();			//ignore the newline char
			getline(cin, name);
			cin >> subject;
			cin >> avail;

			if (subject != "Math" && subject != "Science" && subject != "English" && subject != "History")
			{
				cout << "You have entered in a wrong subject." << endl;
			}
			else
			{
				tree.insert(name, subject, avail);
			}
			break;
		case 3:
			tree.display();
			break;
		default:
			cout << "Invalde choice." << endl;
			break;
		}

		cout << "Do you want to continue? Y or N" << endl;
		cin >> choice;
		cout << endl;
	}
	
	return 0;
}