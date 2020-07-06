#include <iostream>
#include "volume.h"
using namespace std;

const double pi = 3.14;

// Volume of a sphere: 4/3 pi r^3
double volume(double r) { // r is radius
	return pi * r*r*r * 4 / 3;
}

// Volume of a cube: a^3
double volume(int a) { // a is length of side
	return a*a*a;
}

// Volume of a cylinder: (pi r^2) * h [area of circle times height]
double volume(double r, int h) { // r is radius, h is height
	return pi * r*r * h;
}
