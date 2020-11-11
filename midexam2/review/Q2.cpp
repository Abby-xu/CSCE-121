//Maximum Gains

#include <iostream>
#include <vector>

using namespace std;

double moneyGrab(const vector<vector<int>>& grid, int row) {
	double sum = grid.at(row).at(0);
	int rows = grid.size();
	int cols = grid.at(0).size();
	int curr_y = row;
	int num1, num2, num3;

	if(row > rows || row < 0) {
		cout << "invalid input for row, exiting..." << endl;
		exit(1);
	}

	for (int i = 1; i < cols; i++) {
		// cout << "curr_y is: " << curr_y << endl;

		//calculate the change for different situations
		if (curr_y == 0) {
			num2 = grid.at(curr_y).at(i);
			num3 = grid.at(curr_y + 1).at(i);
		} else if (curr_y == (rows - 1)) {
			num1 = grid.at(curr_y - 1).at(i);
			num2 = grid.at(curr_y).at(i);
		} else {
			num1 = grid.at(curr_y - 1).at(i);
			num2 = grid.at(curr_y).at(i);
			num3 = grid.at(curr_y + 1).at(i);
		}
		// cout << "num2: " << num2 << endl;

		//choose path
		if (curr_y == 0) {
			if (num2 > num3) {
				sum += num2;
			} else {
				sum += num3;
				curr_y += 1;			
			}
		} else if (curr_y == (rows - 1)) {
			if (num1 < num2) {
				sum += num2;				
			} else {
				sum += num1;
				curr_y -= 1;				
			}
		} else {
			if ((num2 > num1) && (num2 > num3)) {
				sum += num2;				
			} else if ((num3 > num2) && (num3 > num1)) {
				sum += num3;
				curr_y += 1;
			} else {
				sum += num1;
				curr_y -= 1;
			}			
		}
		// cout << "sum: " << sum << endl;
	}
	return sum;
}

// double moneyGrab(const vector<vector<int>>& grid, int row){
//   int i;
//   double position =  grid.at(row).at(i);
//   double sum = grid.at(row).at(0);
//   if (row > grid.size()){
//     throw runtime_error("Row doesnt exist");
//   }

//   for(i = 0; grid.at(row).size()-1; i++){

//     // straight = grid.at(row).at(i+1)
//     // strFrwd =
//     // strDown =
//     if(row == grid.size()-1){
      

//     }

//     if(grid.at(row).at(i+1) > position){
//       sum += grid.at(row).at(i+1);
//       position = grid.at(row).at(i+1);

//     }
//     else if(grid.at(row-1).at(i+1) > position){
//       sum+=grid.at(row-1).at(i+1);
//       position = grid.at(row-1).at(i+1);

//     }
//     else if(grid.at(row+1).at(i+1) > position){
//       sum+=grid.at(row+1).at(i+1);
//       position=grid.at(row+1).at(i+1);

//     }

//   }
//   return sum;

// }

int main() {
	std::vector<vector<int>> grid = {
		{14,	4,	22,	23,	18},
		{5,		3,	8,	15,	19},
		{17,	7,	9,	25,	2},
		{20,	21,	1,	12,	10},
		{13,	16,	24,	11,	6}};
	cout << "Testing for row == 3: ..." << endl;
	cout <<	moneyGrab(grid, 3) << endl;
	cout << "Testing for row == 1: ..." << endl;
	cout << moneyGrab(grid, 1) << endl;
	return 0;
}
