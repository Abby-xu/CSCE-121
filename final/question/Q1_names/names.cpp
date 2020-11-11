#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
vector<string> names;
vector<int> UINs;
string input;
string filename = "names.dat";
ifstream inFS;
int nextUIN = 101001001;

	inFS.open(filename);
	if (!inFS.is_open()) {
      cout << "Error: Unable to open " << filename << endl;
   }

	 while (inFS >> input) {
     names.push_back(input);
    }
    inFS.close();

    cout << "\nAll names read.\n\n";

/* Part 1, Your code Here.
	Use a range based loop to print out one name per line from 
the vector names.
	*/

	for (string a : names) {
		cout << a << endl;
	}

    cout << "\nAll names written by range." << endl;

    cout << "UINs being created..." << endl;

		/* Part 2, Your code here.
			Use a range base loop to print fill a parallel
vector of UINs, by incrementing nextUIN each time after you use it.
Each location in names, with a name, should get a UIN.  */
    for (string b : names) {
    	UINs.push_back(nextUIN);
    	nextUIN += 1;
    }

			cout << "UINs created..." << endl;

		/* part 3, your code here. Create a loop that prints out 
"Name:  (the name)  UIN:  (the uin)"
		one per line. */
	for (int i = 0; i < names.size(); i++) {
		cout << "Name: " << names.at(i) << " UIN: " << UINs.at(i) << endl;
	}
		cout << "All done..." << endl;


   return 0;
 }