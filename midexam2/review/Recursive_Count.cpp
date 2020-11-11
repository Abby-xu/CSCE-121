#include <iostream>
using namespace std;
#include <vector>
int countEqual(const vector<int>& numbers, int n, int x){
  try{
    if(n > numbers.size() && n < 0){
      throw runtime_error("not match the size of the vector");
    }

  if(n == 0){
    // if(numbers.at(n) == x){
    //   return 1;
    return 0;
    //  }
    // else{
    //   return 0;
    //  }
    // return 0;
  }
  else{
    //numbers.resize(n);

    if(numbers.at(n-1) == x){
      return 1 + countEqual(numbers,n - 1 , x);
      }
    else{
      return countEqual(numbers,n - 1 , x);
      }
    }
  }
  catch(exception& e){
    cout << e.what() << endl;
    exit(0);
  }
}

int main(){
  int n; int x;
  cout << "Please enter the range: (start with 0) ";
  cin >> n;
  cout << "Enter a number that you wanna find: ";
  cin >> x;
  vector<int>numbers = {1,1,2,3,4,1,2,6,5,3};
  cout << countEqual(numbers,n,x);

}
