#include <iostream>
#include <math.h>

/*
Name:	Rong Xu
Course:	CSCE121_398
UIN:	928009312
		HW_1
*/

using namespace std;

int main(int argc, char const *argv[])
{
	//get a, b, c from user input
	double a, b, c;
	cin >> a >> b >> c;

	//output the equation needed be solved
	if (b < 0 && c >= 0) {
		cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0"<< endl;
	}
	else if (b < 0 && c < 0) {
		cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0"<< endl;
	}
	else if (b >= 0 && c < 0) {
		cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0"<< endl;
	}
	else {
		cout << a << "x^2 + " << b << "x + " << c << " = 0"<< endl;
	}

	if (a != 0) {
		//calculate the delta and root
		double delta = pow(b, 2) - 4 * a * c;
		double root = pow(delta, 0.5);

		if (delta > 0) {
			//case 1
			double x1 = (-b - root) / (2 * a);
			double x2 = (-b + root) / (2 * a);
			cout << "x = " << x1 << endl;
			cout << "x = " << x2 << endl;
		}

		else if (delta == 0) {
			//case 2
			double x = -b / (2 * a);
			cout << "x = " << x << endl;
		}

		else {
			//case 3 
			root = fabs(pow((4 * a * c - pow(b, 2)), 0.5));
			double x3 = (-b / 2 / a);
			if (a > 0) {
				cout << "x = " << x3 << " - " << root / 2 / a << "i" << endl;
				cout << "x = " << x3 << " + " << root / 2 / a << "i" << endl;
			}
			else {
				cout << "x = " << x3 << " + " << root / 2 / fabs(a) << "i" << endl;
				cout << "x = " << x3 << " - " << root / 2 / fabs(a) << "i" << endl;
			}

		}
	}
	else if (a == 0 && b != 0) {
		//case 4 for when a = 0, b*x + c = 0
		double x = -c / b;
		cout << "x = " << x << endl;
	}

	else {
		//case 5 for both of a and b are 0
		cout << "Unable to determine root(s)." << endl;
	}
	
	return 0;
}