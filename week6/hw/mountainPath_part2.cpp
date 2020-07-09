#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include "functions.h"

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
    ifstream inFS{fileName};//测试地址：Desktop/2020_summer/CSCE121/HW/hw5/map-input-480-480.dat   map-input-87-189.dat 
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
	//调用原2D vector计算RGB分配到R，G，B三个2D vector中
	vector<vector<int>> R(rows, vector<int> (columns));
	vector<vector<int>> G(rows, vector<int> (columns));
	vector<vector<int>> B(rows, vector<int> (columns));
	for(i = 0; i < rows; i++) {
		for(j = 0; j < columns; j++) {
			R.at(i).at(j) = round(double(fileData2D.at(i).at(j) - min) / double(max - min) * 255.0);
			G.at(i).at(j) = round(double(fileData2D.at(i).at(j) - min) / double(max - min) * 255.0);
			B.at(i).at(j) = round(double(fileData2D.at(i).at(j) - min) / double(max - min) * 255.0);
		}
	}
//step4 
	//write function to compute the greedy path in the functions.cpp

//step5
	vector<int> pathAll;
	int r = 252, g = 25, b = 63;
	for (int i = 0; i < rows; ++i) {
		int sum = colorPath(fileData2D, R, G, B, r, g, b, i);
		pathAll.push_back(sum);
	}

//step6
	int x = 0, MIN = pathAll.at(0);
	for (i = 1; i < pathAll.size(); ++i) {
		if (pathAll.at(i) < MIN){
			MIN = pathAll.at(i);
			x = i;
		}
	}
	r = 31, g = 253, b = 13;
	int sum = colorPath(fileData2D, R, G, B, r, g, b, x);

//step7
	ofstream outFS{fileName + ".ppm"};
	outFS << "P3" << endl;
	outFS << columns << " " << rows << endl;
	outFS << "255" << endl;

	for(i = 0; i < rows; i++) {
		for(j = 0; j < columns; j++) {
			outFS << R.at(i).at(j) << " ";
			outFS << G.at(i).at(j) << " ";
			outFS << B.at(i).at(j) << " ";
		}
	}
	outFS << endl;
	outFS.close();

	return 0;
}