#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
    // get a seed value for the pseudo-random number generator
    cout << "Enter seed value: ";
    int rseed;
    cin >> rseed;
    srand(rseed);
    cout << endl;

    // define constants for random values
    const int NUM_VALUES = 100;
    const int RANGE = 10000;

    // populate a vector with random values
    vector<int> values;
    for (int i = 0; i < NUM_VALUES; i++)
    {
        int val = rand() % RANGE;
        values.push_back(val);
    }

    // iterate through vector and print values
    // COMMENT OUT OR REMOVE THIS FOR LOOP FOR YOUR VOCAREUM SUBMISSION
    for (int i = 0; i < NUM_VALUES; i++)
    {
        cout << setw(5) << values.at(i);
        if ((i + 1) % 10 == 0) cout << endl; // new line every 10 numbers
        // For fun, change i+1 to just i above, run and
        //    see how that affects the output
    }
    cout << endl;

    int min = values[0], max = values[0];
    double avg, sum = 0;

    /*
        Students: This is where your code will go to find the
        min, max, and average values in the vector.
    */

    for (int i = 0; i < values.size(); ++i) {
        if (values[i] < min) {
            min = values[i];
        }
        if (values[i] > max) {
            max = values[i];
        }
        sum += values[i];
    }
    avg = sum / values.size();
    /*
        Be sure to initialize your min, max, sum, and average values
        appropriately.
    */

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << avg << endl;
}