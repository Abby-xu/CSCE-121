//Minus Odd Column

#include <iostream>
#include <vector>

using namespace std;

void minusOddColumn(vector<vector<int>>& mat);

int main () {
	std::vector<std::vector<int>> v = {
		{0,	30,	10,	70,	10},
		{30,0,	45,	100,50},
		{10,45,	0,	85,	20},
		{70,100,85,	0,	100},
		{10,50,	20,	100,0}
	};

	minusOddColumn(v);

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[0].size(); j++) {
			cout << v.at(i).at(j) << " ";
		}
		cout << endl;
	}

	return 0;
}

void minusOddColumn(std::vector<std::vector<int>>& mat) {
	int targetC = 0;
	int curr_Max = 0;
	int nRows = mat.size();
	int nCols = mat[0].size();

	for (int i = 0; i < nCols; i++) {
		int count = 0;
		for (int j = 0; j < nRows; j++) {
			if (mat[j][i] % 2 == 1)
				count += 1;
		}
		if(count > curr_Max) {
			curr_Max = count;
			targetC = i;
		}
	}
	for (int i = 0; i < nRows; i++) {
		mat[i][targetC] = -1;
	}
}