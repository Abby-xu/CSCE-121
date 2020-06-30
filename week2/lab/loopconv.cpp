#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int i = -55; // set to non intuitive value

	cout << setfill('*') << setw(30) << "" << endl;

	cout << "Loop A (while version)" << endl;
	i = 0; // initialization
	while (i < 10) { // termination condition
		cout << "Enter a number less than 10 (Greater than 10 to exit):" << endl;
		cin >> i; // update
		cout << "Number: " << i << endl;
	}

	cout << setfill('*') << setw(30) << "" << endl;

	cout << "Loop A (for version)" << endl;
	// We've done the first one for you!
    // Add for loop code, don't forget initialization, termination condition and update 
	// Note: initialization, termination condition and update should 
	//       all be in the () after the 'for' keyword!()
	bool first = true;
	for (i = 0; i<10; cin>>i) {
		if (!first)
			cout << "Number: " << i << endl;
		else
			first = false;
		if (i<10)
			cout << "Enter a number less than 10 (Greater than 10 to exit):" << endl;
	}
	cout << "Number: " << i << endl;

	//***********************************************************************
	cout << setfill('*') << setw(30) << "" << endl;
	
	cout << "Loop B (for version)" << endl;
	for (i = 0; i<5; i++) { //(initialization; termination condition; update)
		cout << i << endl;
	}

	cout << setfill('*') << setw(30) << "" << endl;
	cout << "Loop B (do while version)" << endl;
	// Add do while loop code, don't forget initialization, termination condition and update
	i = 0; // initialization
	while (i < 5) { // termination condition
		cout << i << endl;
		i++;
	}
    //***********************************************************************
	cout << setfill('*') << setw(30) << "" << endl;


	cout << "Loop C (do while version)" << endl;
	i = 20;  // initialization
	do {
		cout << i * 2 << endl; // output
		i -= 2; // update
	} while (i>10); // termination condition
	
	cout << setfill('*') << setw(30) << "" << endl;

	cout << "Loop C (for version)" << endl;
	// Add for loop code, don't forget initialization, termination condition and update
	for (i = 20; i > 10; i = i - 2) {
		cout << i * 2 << endl;
	}
	cout << setfill('*') << setw(30) << "" << endl;

}

