#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;

int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
    // needed to autograde some test cases in Mimir 
    // do not call srand again in your program
    // Your code starts here

    //let user input the number of digit(or the code for '0') in code
    int inputDigit, enterCode, numDigit;
    cout << "Enter number of digits in code (3, 4 or 5): ";
    cin >> inputDigit;
    while ((inputDigit != 0) && (inputDigit != 3) && (inputDigit != 4) && (inputDigit != 5)) {
    	cout << "Enter number of digits in code (3, 4 or 5): ";
        cin >> inputDigit;
    }
    if (inputDigit == 0) {
    	cout << "Enter code: ";
    	cin >> enterCode;
    	cout << "Enter number of digits in code: ";
    	cin >> numDigit;    
    } else {
        numDigit = inputDigit;
    }

    //tranfer the code into vector form
    vector<int> guessNumR(numDigit);         
    if (inputDigit == 0) {
        for (int i = 0; i < numDigit; ++i) {
            guessNumR[i] = enterCode % 10;
            enterCode /= 10;
        }
    } else {
        guessNumR[0] = rand() % 10;
        int dig;
        for (int i = 1; i < numDigit; ++i) {
            bool isSame = true;
            while (isSame) {
                dig = rand() % 10;
                for (int j = 0; j < i; ++j) {
                    if (guessNumR[j] == dig) {
                        isSame = true;
                        break;
                    } else {
                        isSame = false;
                    }
                }              
            }
            guessNumR[i] = dig;
        }
    }

    //reverse the vector form and print it out
    vector<int> guessNum(numDigit);
    for (int j = 0; j < numDigit; ++j) {
        guessNum[j] = guessNumR[(numDigit-j-1)];
    }

    cout << "Number to guess: " << guessNum.at(0);
    for (int i = 1; i < guessNum.size(); i++) {
        cout << "-" << guessNum[i];
    }
    cout << endl;

    int userGuess;
    //make a loop for user guess
    while (true) {
        vector<int> userGuessVR;
        vector<int> userGuessV;
    	cout << "Enter Guess: ";
    	cin >> userGuess;
        int i = 0;
        int testUserGuess = userGuess;
        while (testUserGuess != 0) {
            testUserGuess /= 10;
            ++i;
        }
        //transfer the user guess into vector form
        for (int j = 0; j < numDigit; ++j) {
            userGuessVR.push_back(userGuess % 10);
            userGuess /= 10;
        }
        for (int k = 0; k < numDigit; ++k) {
            userGuessV.push_back(userGuessVR[(numDigit-k-1)]);
        }

        //if the code is invalid
        bool ifSame = false;
        for (int j = 0; j < userGuessV.size(); ++j) {
            for (int k = j + 1; k < userGuessV.size(); ++k) {
                if (userGuessV[j] == userGuessV[k]) {
                    ifSame = true;
                }
            }
        }
        if (i > numDigit) {
            cout << "You can only enter " << numDigit << " digits." << endl;
            continue;
        } else if (ifSame == true) {
            cout << "Each number must be different." << endl;
            continue;
        }

        //calculate the bulls and cows
        int bulls = 0, cows = 0;
        for (int i = 0; i < numDigit; ++i) {
            if (userGuessV[i] == guessNum[i]) {
                bulls += 1;
            } else {
                for (int j = 0; j < numDigit; ++j) {
                    if (userGuessV[i] == guessNum[j]) {
                        cows += 1;
                    }
                }
            }
        }
        
        if (bulls != numDigit) {
            cout << bulls << " bulls" << endl;
            cout << cows << " cows" << endl;            
        } else {
            cout << numDigit << " bulls... " << userGuessV.at(0);
            for (int i = 1; i < userGuessV.size(); i++) {
                cout << "-" << userGuessV[i];
            }
            cout << " is correct!" << endl;
            break;
        }
    }   		 
}