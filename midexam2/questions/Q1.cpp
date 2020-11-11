/*
Your goal is to write a function that builds a 10 x 10 2D vector. 
The vector returned should be populated with counting by 5's starting with 5, 10, 15, 20, ... where 5 is in position 0,0   
Fill each row, then move down to the next row.

Your second function is to print out the vector one row at a time with a space and a comma between each number.

Your third function should return the average of all of the numbers in the vector.

Your main will print the returned value. Use the code provided. You will need to update main and each of the three functions.

Here is the output if we did a 3x3 (example only)
j = 0, i = i

5, 10, 15,   i = 0, j = j seconf for loop
20, 25, 30,
35, 40, 45,
The average of your 3 by 3 vector is: 25
*/

#include <vector>
  #include <iostream>
  using namespace std;

  void buildVector(vector<vector <int>>&, int);
  void printVector(vector<vector <int>>, int);
  double averageVector(vector<vector <int>>, int);

  int main() {
    int size;  // size of 2 d array

    /* your code here */
    size = 10;

    vector<vector<int>> vect( size , vector<int> (size));

    buildVector(vect, size);
    printVector(vect, size);
    cout << "The average of your " << size << " by " << size
      << " vector is: " << averageVector(vect, size) << endl;
    return 0;
  }

  void buildVector(vector<vector <int>>& vect, int s){
    /* your code here */
    for (int i = 0; i < s; ++i) {
      for (int j = 0; j < s; ++j) {
        vect[i][j] = i * s * 5 + 5 * j + 5;
      }
    }
  }

  void printVector(vector<vector <int>> vect, int s){
      /* your code here */
    for (int i = 0; i < s; ++i) {
      for (int j = 0; j < s; ++j) {
        cout << vect[i][j] << ", ";
      }
    cout << endl;
  }
}

  double averageVector(vector<vector <int>> vect, int s){
      /* your code here */
    int sum = 0;
    for (int i = 0; i < s; ++i) {
      for (int j = 0; j < s; ++j) {
        sum += vect[i][j];
      }
    }
    return double(sum) / s / s;  // replace 0.0 with correct value only here to compile.
  }