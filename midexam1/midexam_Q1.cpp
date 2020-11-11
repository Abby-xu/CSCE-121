#include <iostream>
using namespace std;

int getNumber();
string checkprintOddEven(int n);
void printOddEven(string s);

int main() {

  int number = getNumber();
  string oddEven = checkprintOddEven(number);
  printOddEven(oddEven);
  return 0;
}

int getNumber(){
	/* your code here */
	int num;
	cout << "Input an integer: ";
	cin >> num;
	return num;
}

string checkprintOddEven(int n){
	/* your code here */
	if (n % 2 == 0) {
		return "Even";
	} else {
		return "Old";
	}
}
void printOddEven(string s){
	/* your code here */
	cout << "Your number is " << s << ".";
}