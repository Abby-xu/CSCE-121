#include <iostream>
#include <vector>
#include <cmath>



using namespace std;

double continuousFraction(vector<double> x, int n){
  double result;
  if (n > x.size()){
    throw runtime_error("N is larger than vector size.");
  }
  if (n!=0){
  while (n>0){
    result = fabs((1+(x.at(n-1)/continuousFraction(x, n-1))));
    return result;
  }
}
  if (n==0){
  return -1;
  }
}




int main(){
  vector<double> vect;
      vect.push_back(1);
      vect.push_back(2);
      vect.push_back(3);
      vect.push_back(4);
try {
cout<< "RESULT: "<< continuousFraction(vect, 3)<<endl;
}

catch (runtime_error& exc){
  cout<< exc.what() <<endl;
}
return 0;
}
