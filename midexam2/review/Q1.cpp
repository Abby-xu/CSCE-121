//Path Length

#include <iostream>
#include <vector>

using namespace std;
double pathLength(const std::vector<std::vector<double>>& distance,
				const std::vector<int>& path) {
	double tot_length = 0.0;
	for (int i = 0; i < path.size(); i++) {
		tot_length += distance[path[i]][path[i + 1]];
	}
	return tot_length;
}

int main() {
	std::vector<std::vector<double>> distance = {
		{0.0, 	30.0, 	10.0, 	70.0, 	10.0},
		{30.0, 	0, 		45.0, 	100.0, 	50.0},
		{10.0, 	45.0, 	0, 		85.0, 	20.0},
		{70.0, 	100.0,	85.0, 	0, 		100.0},
		{10.0, 	50.0, 	20.0, 	100.0, 	0}};
	std::vector<int> path = {0, 1, 0, 3, 2, 0};
	cout << pathLength(distance, path);

	return 0;
}