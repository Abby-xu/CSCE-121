#include<iostream>
#include<limits>
using namespace std;

int factorial(int n);

int main()
{
	int value;
	cout << "Enter a positive integer: ";
	cin >> value;

	while (!cin.good()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a positive integer: ";
		cin >> value;
	}

	cout << value << "! = " << factorial(value) << endl;

}

// FIXME 1
// Update the factorial function for each of the fixes
int factorial(int value)
{  
	// FIXME 1A: Add a base case to handle when value == 0, 
	//           you should return 1  
	// Use an if condition to check the value == 0 
	if (value == 0) {
		return 1;
	}

	// FIXME 1B: Add a recursive case to return the updated value
	// e.g., if value is 5, then 5! = 5 x (5-1)!  
	value = value * factorial(value - 1);
	return value; // note this is for the stub, you'll need to update
}