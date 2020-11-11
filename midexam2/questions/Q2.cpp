#include <iostream>

using namespace std;

void rPrint(int n) {
  /* your code here */
	int i = 1;
	if (i < n){
		rPrint(n - 1);
	}
	cout << n << ". I will not zoom bomb." << endl;
}


int main() {
   int n;
      cout << "Enter how many times to repeat sentence: ";
      cin >> n;
      rPrint(n);
}