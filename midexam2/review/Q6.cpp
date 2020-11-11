//Recursive Calculation

#include <iostream>
#include <vector>

using namespace std;

double continuousFraction(std::vector<double> x, int m);

int main() {
	std::vector<double> v = {1, 2, 3, 4};
	cout << continuousFraction(v, 4);

	return 0;
}

double continuousFraction(std::vector<double> x, int n) {
	if (n > x.size())
		throw std::runtime_error("n > size!");

	double result = 0.0;
	if (n == 0)
		return 1;
	else
		return 1 + abs(x.at(n - 1) / continuousFraction(x, (n - 1)));
}