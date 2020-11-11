#include <iostream>
using namespace std;

int main() {
	while (true) {
		int num, number;
		cout << "Please enter a number between 5 and 20: ";
		
		while (true) {
			cin >> num;
			if (num <= 20 && num >= 5) {
				number = num;
				break;
			} else if (num == 0) {
				cout << "Exit program...";
				exit(0);
			} else {
				cout << "Invalid input, please input again: ";
				continue;
			}
		}
		
		cout << "For " << number << endl;
		for (int i = 0; i <= (num - 1); i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < num; j++) {
					if(j % 2 == 1) {
						cout << "O ";
					} else {
						cout << "X ";
					}
				}
			} else {
				for (int j = 0; j < (num); j++) {
					if(j % 2 == 0) {
						cout << "O ";
					} else {
						cout << "X ";
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}