/*
Program calculates the volume of various shapes based on user input.

Step 1: Compile and Run this program as-is
*/
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <limits>
#include <stdexcept>
using namespace std;

const double pi = 3.14;

// Volume of a sphere: 4/3 pi r^3
double volume(double r)   // r is radius
{
    return pi * r * r * r * 4 / 3;
}

// Volume of a cube: a^3
double volume(int a)   // a is length of side
{
    return a * a * a;
}

// Volume of a cylinder: (pi r^2) * h [area of circle times height]
double volume(double r, int h)   // r is radius, h is height
{
    return pi * r * r * h;
}

// FIXME 1
// Volume of a pyramid: 1/3 (l * w) * h [1/3 area of base times height]
double volume1(int l, int w, double he) //  length and width should be ints, height should be a double
{
    return (l * w) * 1 * (he / 3);
}

int getRange(int maxVal, int minVal, string prompt)
{
    int val = 0;
    cout << prompt;
    cin >> val;
    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Invalid input. Expected a number.");
    }
    return val;
}

// FIXME 2: Update the function to handle case 4.
void processChoice(int choice)
{
    double startTemp = 0;
    double endTemp = 0;
    try {
        double vol = -1.0;
        // volumes are always positive, so initialize to non-valid value
        double r = 0; // radius
        int s; // side
        int h; // height
        int l; //length
        int w; // width
        double he;

        switch (choice) {
        case 1: // Sphere
            cout << "Enter radius: ";
            cin >> r;
            cout << "Sphere volume: " << volume(r) << endl;
            break;
        case 2: // Cube
            cout << "Enter length of side: ";
            cin >> s;
            cout << "Cube volume: " << volume(s) << endl;
            break;
        case 3: // Cylinder
            cout << "Enter radius and height: ";
            cin >> r >> h;
            cout << "Cylinder volume: " << volume(r, h) << endl;
            break;
        case 4: // Pyramid
            cin >> l >> w >> he;
            cout << "Pyramid volume: " << volume1(l, w, he) << endl;
            break;
        case 5: // do nothing we are exiting
            break;
        default:
            throw runtime_error("Invalid Choice: " + to_string(choice));
        }
    } catch (char c) {
        ostringstream oss;
        oss << "Error: '" << c << "' not implemented.";
        throw runtime_error(oss.str());
    }
}

void printMenu()
{
    cout << endl << "Menu" << endl;
    cout << "1: Volume of a sphere" << endl;
    cout << "2: Volume of a cube" << endl;
    cout << "3: Volume of a cylinder" << endl;
    cout << "4: Volume of a pyramid" << endl;
    cout << "5: Exit" << endl << endl;
}

int main()
{
    int minVal = 1;
    int maxVal = 5;
    cout << "Volume Calculator:" << endl;
    int choice = 0;
    while (choice != maxVal) {
        try {
            printMenu();
            choice = getRange(minVal, maxVal, "Enter choice: ");
            processChoice(choice);
        } catch (runtime_error& e) {
            cout << endl << e.what() << endl;
        }
    }
}