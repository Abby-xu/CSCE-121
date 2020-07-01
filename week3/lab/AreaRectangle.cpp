#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    double width = 0, height = 0;

    cout << "Enter the width of the rectangle  : ";
    cin >> width;

    cout << "Enter the height of the rectangle : ";
    cin >> height;

    double area = width * height;
    cout << "The area of that rectangle is     : " << area << endl;

    return 0;
}