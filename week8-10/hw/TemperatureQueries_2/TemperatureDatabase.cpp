#include "TemperatureDatabase.h"

#include <fstream>
#include <sstream>


using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	std::string id;
	int year;
	int month;
	double temperature;

	ifstream inFS {filename};
	if (!inFS.is_open()) {
		cout << "Error: Unable to open input.dat" << endl;
		exit(1);
	}

	while(!inFS.eof()) {
		std::string str = "";
		getline(inFS, str);

		stringstream sl(str);
		sl >> id >> year >> month >> temperature;

		if (sl.fail()) {
			if (temperature != -99.99)
				cout << "Error: Other invalid input." << endl;
		}
		else if ((temperature > 50.0 || temperature < -50.0) && (temperature != -99.99))
			cout << "Error: Invalid temperature " << temperature << endl;
		else if (year > curr_year || year < 1800)
			cout << "Error: Invalid year " << year << endl;
		else if (month > 12 || month < 1)
			cout << "Error: Invalid month " << month << endl;
		else
			records.insert(id, year, month, temperature);
	}

	inFS.close();
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1

	//get input
	std::string id, que;
	int upYr, dwnYr;

	ifstream inFS {filename};
	ofstream outFS{"result.dat"}; //output the file

	if (!inFS.is_open()) {
		cout << "Error: Unable to open queries.dat" << endl;
		exit(1);
	}

	while(!inFS.eof()) {
		std::string str = "";
		getline(inFS, str);

		stringstream sl(str);
		sl >> id >> que >> upYr >> dwnYr;

		if (sl.fail())
			cout << "Error: Other invalid query." << endl;
		else if ((dwnYr < upYr) || (upYr < 1800) || (dwnYr > curr_year))
			cout << "Error: Invalid range " << upYr << "-" << dwnYr << endl;
		else if ((que != "AVG") && (que != "MODE"))
			cout << "Error: Unsupported query " << que << endl;
		else {
			outFS << id << " " << upYr << " " << dwnYr << " " << que << " ";
			if(que == "AVG") {
				double AVG = records.findAVG(id, upYr, dwnYr);
				if (AVG == -99.99)
					outFS << "unknown" << endl;
				else
					outFS << AVG << endl;
			}
			if (que == "MODE") {
				double MODE = records.findMode(id, upYr, dwnYr);
				if (MODE == -99.99)
					outFS << "unknown" << endl;
				else
					outFS << MODE << endl;
			}
		}
	}

	inFS.close();
	outFS.close();
}
