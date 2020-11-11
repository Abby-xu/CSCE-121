//Average Matrix

#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> avgMatrix (const vector<vector<double>>& inVector);

int main () {
	std::vector<std::vector<double>> inVector = {
		{0.5,	2.0,	1.2,	3.0},
		{-1.0,	1.5,	3.0,	2.4},
		{0.0,	1.0,	1.5,	2.0}
	};
	vector<vector<double>> a = avgMatrix(inVector);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

vector<vector<double>> avgMatrix (const vector<vector<double>>& inVector) {
	int nRows = inVector.size();
	int nCols = inVector[0].size();
	vector<vector<double>> a(nRows, vector<double> (nCols));

	if (nRows <= 1 || nCols <= 1)
		throw runtime_error("invalid input!");
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			if (i == 0) {
				if (j == 0)
					a.at(i).at(j) = (inVector[i][j + 1] + inVector[i + 1][j + 1] + inVector[i + 1][j]) / 3;
				else if (j == (nCols - 1))
					a.at(i).at(j) = (inVector[i][j - 1] + inVector[i + 1][j - 1] + inVector[i + 1][j]) / 3;
				else
					a.at(i).at(j) = (inVector[i][j + 1] + inVector[i][j - 1] + inVector[i + 1][j + 1] + inVector[i + 1][j - 1] + inVector[i + 1][j]) / 5;
			} else if (i == (nRows - 1)) {
				if (j == 0)
					a.at(i).at(j) = (inVector[i][j + 1] + inVector[i - 1][j + 1] + inVector[i - 1][j]) / 3;
				else if (j == (nCols - 1))
					a.at(i).at(j) = (inVector[i][j - 1] + inVector[i - 1][j - 1] + inVector[i - 1][j]) / 3;
				else
					a.at(i).at(j) = (inVector[i][j + 1] + inVector[i][j - 1] + inVector[i - 1][j + 1] + inVector[i - 1][j - 1] + inVector[i - 1][j]) / 5;
			} else {
				a.at(i).at(j) = (inVector[i - 1][j - 1] + inVector[i + 1][j + 1] +
								inVector[i - 1][j + 1] + inVector[i + 1][j - 1] +
								inVector[i - 1][j] + inVector[i + 1][j] +
								inVector[i][j - 1] + inVector[i][j + 1]) / 8;
			}
			// cout << a[i][j] << endl;
		}
	}
	return a;
}
