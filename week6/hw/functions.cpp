#include <iostream>
#include<vector>
#include "functions.h"

using namespace std;
int colorPath(const vector<vector<int>>& heightMap, 
				vector<vector<int>>& r, vector<vector<int>>& g, 
				vector<vector<int>>& b, int color_r, int color_g, 
				int color_b, int start_row) {
	
	int curr_y = start_row, sum = 0;
	int nCols = heightMap[0].size(), nRows = heightMap.size();
	int alt, elevChange1, elevChange2, elevChange3;
	//check if start_row is invalid
	if (curr_y < 0 || curr_y >= nRows) {
		cout << "Invalid input." << endl;
		exit(1);
	}

	r.at(curr_y).at(0) = color_r;
	g.at(curr_y).at(0) = color_g;
	b.at(curr_y).at(0) = color_b;
	for (int i = 1; i < nCols; i++) {
		alt = heightMap.at(curr_y).at(i - 1);
		//calculate the change for different situations
		if (curr_y == 0) {
			elevChange2 = abs(heightMap.at(curr_y).at(i) - alt);
			elevChange3 = abs(heightMap.at(curr_y + 1).at(i) - alt);
		} else if (curr_y == (nRows - 1)) {
			elevChange1 = abs(heightMap.at(curr_y - 1).at(i) - alt);
			elevChange2 = abs(heightMap.at(curr_y).at(i) - alt);
		} else {
			elevChange1 = abs(heightMap.at(curr_y - 1).at(i) - alt);
			elevChange2 = abs(heightMap.at(curr_y).at(i) - alt);
			elevChange3 = abs(heightMap.at(curr_y + 1).at(i) - alt);
		}

		//choose path
		if (curr_y == 0) {
			if (elevChange2 <= elevChange3) {
				r.at(curr_y).at(i) = color_r;
				g.at(curr_y).at(i) = color_g;
				b.at(curr_y).at(i) = color_b;
				sum += elevChange2;
			} else {
				r.at(curr_y + 1).at(i) = color_r;
				g.at(curr_y + 1).at(i) = color_g;
				b.at(curr_y + 1).at(i) = color_b;
				sum += elevChange3;
				curr_y += 1;			
			}
		} else if (curr_y == (nRows - 1)) {
			if (elevChange1 >= elevChange2) {
				r.at(curr_y).at(i) = color_r;
				g.at(curr_y).at(i) = color_g;
				b.at(curr_y).at(i) = color_b;
				sum += elevChange2;				
			} else {
				r.at(curr_y - 1).at(i) = color_r;
				g.at(curr_y - 1).at(i) = color_g;
				b.at(curr_y - 1).at(i) = color_b;
				sum += elevChange1;
				curr_y -= 1;				
			}
		} else {
			if (((elevChange1 == elevChange2) && (elevChange2 == elevChange3)) || 
				((elevChange2 == elevChange3) && (elevChange2 < elevChange1)) || 
				((elevChange2 == elevChange1) && (elevChange2 < elevChange3)) || 
				((elevChange2 < elevChange1) && (elevChange2 < elevChange3))) {
				r.at(curr_y).at(i) = color_r;
				g.at(curr_y).at(i) = color_g;
				b.at(curr_y).at(i) = color_b;
				sum += elevChange2;				
			} else if (((elevChange1 == elevChange3) && (elevChange1 < elevChange2)) || 
						((elevChange3 < elevChange2) && (elevChange3 < elevChange1))) {
				r.at(curr_y + 1).at(i) = color_r;
				g.at(curr_y + 1).at(i) = color_g;
				b.at(curr_y + 1).at(i) = color_b;
				sum += elevChange3;
				curr_y += 1;
			} else {
				r.at(curr_y - 1).at(i) = color_r;
				g.at(curr_y - 1).at(i) = color_g;
				b.at(curr_y - 1).at(i) = color_b;
				sum += elevChange1;
				curr_y -= 1;
			}			
		}
	}
	return sum;
}