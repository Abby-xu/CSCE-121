#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    // get a seed value for the pseudo-random number generator (no cout prompt)
    int rseed;
    int NUM_VALUES = 100;
    cout << "Enter seed value: ";
    cin >> rseed;
    cout << "Enter number of integers: ";
    cin >> NUM_VALUES;
    srand(rseed);
    cout << endl;

    // define constants for random values
    const int RANGE = 10000;

    // populate a vector with random values
    vector<int> values;
    for (int i = 0; i < NUM_VALUES; i++)
    {
        int val = rand() % RANGE;
        values.push_back(val);
    }

    sort (values.begin(), values.end());

    // iterate through vector and print values
    // COMMENT OUT OR REMOVE THIS FOR LOOP FOR YOUR VOCAREUM SUBMISSION
    for (int i = 0; i < NUM_VALUES; i++)
    {
        cout << setw(5) << values.at(i);
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;

    int min, max;
    double median;

    /*
        Students: This is where your code will go to find the
        min, max, and median values in the vector.
        */
    min = values[0];
    max = values[(values.size()-1)];
    if (values.size() % 2 == 1) {
        median = values[(values.size() / 2)];
    } else {
        median = (values[values.size() / 2 - 1] + values[values.size() / 2]) /2;
    }
    /*
        HINT: You will not use any loops for this!
    */

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Median: " << median << endl;
}
