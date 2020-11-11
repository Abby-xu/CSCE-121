//Recursive Count

#include <iostream>
#include <vector>

using namespace std;

int countEqual(const vector<int>& numbers, int n, int x);

int main() {
	vector<int> numbers = {3,5,4,3,2,3,4,3};

	cout << countEqual(numbers, 7, 3);
}

int countEqual(const vector<int>& numbers, int n, int x) {
	if (n > numbers.size())
		throw std::runtime_error("n > size!");
	int count = 0;
	if (n == 0) {
		return 0;
	}
	if (x == numbers.at(n-1)) {
		count = 1;
	} 
	return count + countEqual(numbers, (n-1), x);

}

/*
vector = {3, 5, 4, 3, 2, 3}
n = 6
x = 3
cout = 3
*/

  