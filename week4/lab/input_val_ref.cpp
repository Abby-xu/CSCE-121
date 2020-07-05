#include <iostream>
#include <limits>
using namespace std;

int main() {

	int value = 0;

	while (value != -9) {
		cout << "Enter an integer (or -9 to exit): ";
		cin >> value;
		// EDIT3A uncomment the next line
		if (!cin.good()) {
			// EDIT1 uncomment the next line
			cin.clear();
			// EDIT2 uncomment the next line
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// EDIT3B uncomment the next line
		}
		// EDIT3C uncomment the next line
		else {
			cout << "You entered: " << value << endl << endl;
		// EDIT3D uncomment the next line
		}

		if (value == -9)
			return 0;
	}


}     