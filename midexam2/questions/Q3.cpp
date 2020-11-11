#include<iostream>
using namespace std;

class Time
{
    int hr, min, sec;
    public:
    // default constructor
    Time()
    {
        hr=0, min=0; sec=0;
    }

    // overloaded constructor
    Time(int h, int m, int s)
    {
        hr=h, min=m; sec=s;
    }

    int GetHr() const
    {
      return this-> hr;
    }

    int GetMin() const
    {
      return this-> min;
    }

    int GetSec() const
    {
      return this-> sec;
    }

};

// define the overloaded function
ostream& operator << (ostream &out, Time &tm)
{
  //replace Your code here //
    //3 hour : 15 min : 45 sec
    out << "Time is: ";
    out << tm.GetHr() << " hour : " << tm.GetMin() << " min : " << tm.GetSec() << "sec" << endl;
    return out;
}

int main()
{
    Time tm(3,15,45);
    cout << tm;
    return 0;
}