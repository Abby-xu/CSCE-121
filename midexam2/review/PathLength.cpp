#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////
double pathLength(const vector<vector<double>>& distance, const vector<int>& path);

void print(std::vector<int> const &path)
{
  cout << "Path" << endl;
	for (int i = 0; i < path.size(); i++) {
		cout << path.at(i) << ' ';
	}
  cout<< endl << endl;
}
////////////////////////////////////////////////////////////////////////////////

void printVector(std::vector<vector<double>> const &distance){
  cout << "Distance" << endl;
  for(int i = 0; i < distance.size(); i++){
    for( int j = 0; j < distance.at(i).size(); j++){
      cout << distance.at(i).at(j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}

////////////////////////////////////////////////////////////////////////////////

int main() {

std::vector<int> path = { 0, 1, 0, 3, 2, 0};

std::vector<vector<double>> distance = {{0.0,  30.0,  10.0, 70.0,  10.0},
                                        {30.0, 0,     45,   100.0, 50},
                                        {10,   45.0,  0,    85.0,  20},
                                        {70.0, 100.0, 85.0, 0,     100},
                                        {10.0, 50.0,  20.0, 100.0, 0}};
printVector(distance);
print(path);
cout << pathLength(distance,path);
cout << endl;

}

////////////////////////////////////////////////////////////////////////////////

double pathLength(const vector<vector<double>>& distance, const vector<int>& path){

double Value = 0;
double tot = path.size();

for ( int i = 0; i < tot; i++){

  int x = path[i];
  int y = path[i + 1];
  Value += distance[x][y];
}
cout << "Path Length" << endl;
return Value;
}
