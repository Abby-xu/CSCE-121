#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
double continuousFraction(vector<double> x, int n){
  try{
    if(n > x.size() || n < 0){
      throw runtime_error("n size is too wider");
    }
    if(n == 0){
      //return abs(x.at(n+1) / (1+ x.at(n)));
      //return 1 + x.at(n);
      return 1;
    }
    else{
      return 1 + abs(x.at(n-1)/continuousFraction(x,n-1));
    }
  }
  catch(exception& e){
    cout << e.what() << endl;
    exit(0);
  }
}

int main(){
  vector<double>num_vector = {2};
  cout << "Enter a number: ";
  int n; cin >> n;
  cout << continuousFraction(num_vector,n);

}
