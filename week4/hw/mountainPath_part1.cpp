#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
int main() {

//step1
	string fileName;
	int rows, columns, i, j, k;

	cin >> rows;
	if (!cin.good()) {
		cout << "Error: rows input invalid!";
		return -1;
	} else if (rows <= 0) {
		cout << "Error: rows cannot be negative!";
		return -1;
	}
	cin >> columns;	
	if (!cin.good()) {
		cout << "Error: columns input invalid!";
		return -1;
	} else if (columns <= 0) {
		cout << "Error: columns cannot be negative!!";
		return -1;
	}
	cin >> fileName;
	if (!cin.good()) {
		cout << "Error: filename input invalid!";
		return -1;
	}

    int temp, MAX_SIZE = rows * columns;   
	vector<vector<int>> fileData2D(rows, vector<int> (columns));
    ifstream inFS{fileName};//测试地址：Desktop/2020_summer/CSCE121/HW/hw4/map-input-87-189.dat
    if (!inFS.is_open()) {
    	cout << "Error: cannot open file!";
    	return 1;
    }
    for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			inFS >> fileData2D.at(i).at(j);
			if (inFS.fail()) {
				cout << "Error: invalid data!";
				return -2;
			}
		}
	}
	inFS >> temp;
	if (!inFS.fail()) {
		cout << "Error: Too many data elements!";
		return -2;
	}

//step2
	int min = fileData2D.at(0).at(0), max = fileData2D.at(0).at(0);
	for(i = 0; i < rows; i++) {
		for(j = 0; j < columns; j++) {
			if (fileData2D.at(i).at(j) < min) {
				min = fileData2D.at(i).at(j);
			} else if (fileData2D.at(i).at(j) > max) {
				max = fileData2D.at(i).at(j);
			}
		}
	}
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
//step3
	vector<vector<int>> RGB(MAX_SIZE, vector<int> (3));
	for(i = 0; i < rows; i++) {
		for(j = 0; j < columns; j++) {
			for(k = 0; k < 3; k++) {
				RGB.at(i * columns + j).at(k) = round(double(fileData2D.at(i).at(j) - min) / double(max - min) * 255.0);
			}
		}
	}

//step4
	ofstream outFS{fileName + ".ppm"};
	outFS << "P3" << endl;
	outFS << columns << " " << rows << endl;
	outFS << "255" << endl;

	for(i = 0; i < MAX_SIZE; i++) {
		for(j = 0; j < 3; j++) {
			outFS << RGB.at(i).at(j) << " ";
		}
	}
	outFS << endl;
	outFS.close();

	return 0;
}