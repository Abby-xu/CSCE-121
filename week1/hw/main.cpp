#include <iostream>

/*
Name:	Rong Xu
Course:	CSCE121_398
UIN:	928009312
		HW_1
*/

using namespace std;

int main() {

	string firstName;
	string lastName;
	int birthYear;
	int feetHeight;
	int inchHeight;

	//ask user for basic info
	cout << "First name: ";
	cin >> firstName;

	cout << "Last name: ";
	cin >> lastName;

	cout << "Birth year: ";
	cin >> birthYear;

	cout << "Height in feet (do not include inches): ";
	cin >> feetHeight;

	cout << "Height in inches (do not include feet): ";
	cin >> inchHeight;
	cout << endl;

	//user's age
	int age = 2020 - birthYear;

	//user's height in cm
	double cmHeight = (feetHeight * 12 + inchHeight) * 2.54;

	//user's average annual growth
	double avgGrowth = (cmHeight - 51) / age;

	//output the info
	cout << "Hello " << firstName << " " << lastName << "." << endl;
	cout << "You are " << age << " years old in 2020." << endl;
	cout << "Your height is " << cmHeight << " cm." << endl;
	cout << "You grew an average of " << avgGrowth << " cm per year (assuming you were 51 cm at birth).";
	
	return 0;
}