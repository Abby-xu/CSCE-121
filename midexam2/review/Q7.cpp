//Crossing Numbers Recursion

#include <iostream>
#include <vector>

using namespace std;

double f(double x, double y) {
	if (x >= y) {
		return (x+y)/2;
	}
	double p1 = f(x + 2, y - 1);
	double p2 = f(x + 1, y - 2);
	return f(p1, p2);
}

double ff(double x, double y) {
	while (x < y) {
		x += 1;
		y -= 1;
	}
	return (x + y) / 2;
}

int main() {
	cout << f(1, 10);
	cout << ff(1, 10);
	return 0;
}