#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

struct TemperatureData {
	// Put data members here
	std::string id;
	int year;
	int month;
	double temperature;
	
	TemperatureData() : id(""), year(0), month(0), temperature(0.0) {};
	TemperatureData(std::string id, int year, int month, double temperature) : 
								id(id), year(year), month(month), temperature(temperature) {};
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b) {
		if (id < b.id) return true;
		if ((id == b.id) && (year < b.year)) return true;
		if ((id == b.id) && (year == b.year) && (month < b.month)) return true;

		return false;
	};
};

struct Node {
	TemperatureData data;
	Node* next;

	// Default constructor
	Node() : data(), next(nullptr) {}; // remember to initialize next to nullptr
	Node(string id, int year, int month, double temperature) : data(id, year, month, temperature), next(nullptr) {}; // remember to initialize next to nullptr

	// This operator will allow you to just ask if a node is smaller than another
	//  rather than looking at all of the location, temperature and date information
	bool operator<(const Node& b) {
		return this->data < b.data;
	};

  // The function below is written. Do not modify it
	virtual ~Node() {}

};

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	// Default constructor
	LinkedList() : head(nullptr), tail(nullptr) {};

	// Destructor
	~LinkedList(){
		clear();
	};

	// Copy constructor
	LinkedList(const LinkedList& source) {
		head = tail = nullptr;
		for (Node* curr = source.head; curr != nullptr; curr = curr -> next) {
			TemperatureData& data = curr -> data;
			insert(data.id, data.year, data.month, data.temperature);
		}
		cout << endl;
	};

	// Copy assignment
	LinkedList& operator=(const LinkedList& source){
		clear();
		for (Node* curr = source.head; curr != nullptr; curr = curr -> next) {
			TemperatureData& data = curr -> data;
			insert(data.id, data.year, data.month, data.temperature);
		}
		return *this;
	};

	// Insert a record to the linked list
	void insert(std::string location, int year, int month, double temperature){
		if (temperature == -99.99)
			return;
		else {
			Node* n = new Node(location, year, month, temperature);
			if (head == nullptr && tail == nullptr) { //empty
				head = n;
				tail = n;
			} else {
				Node* temp = head;
				Node* pretemp = nullptr;
				while (temp != nullptr) {
					if (*temp < *n) {
						pretemp = temp;
						temp = temp -> next;
					} else{
						if(pretemp == nullptr) {  //first
							pretemp = n;
							head = n;
						} else  //middle
							pretemp -> next = n;
						n -> next = temp;
						return;
					}
				}		//last	
				pretemp -> next = n;
				tail = n;
			}
		}
	};

	// Clear the content of this linked list
	void clear(){
		while (head != nullptr) {
			Node* temp = head -> next;
			delete head;
			head = temp;
		}
	};

	// The functions below are written already. Do not modify them.
	std::string print() const{
		std::stringstream ss;
		Node* curr = head;
		while(curr != nullptr) {
			ss << curr -> data.id << " " << curr -> data.year << " " << curr -> data.month << " " << curr -> data.temperature << endl;
			curr = curr -> next;
		}

		return ss.str();
	};

	Node* getHead() const{
	    return head;
	};

	//find the average of the ll and return the string of result
	double findAVG(std::string location, int upYr, int dwnYr){
		double sum = 0.0;
		int count = 0;
		for (Node* curr = head; curr != nullptr; curr = curr -> next) {
			if((curr -> data.id == location) && (curr -> data.year <= dwnYr) && (curr -> data.year >= upYr)) {
				sum += curr -> data.temperature;
				count ++;
			}
		}

		if (count == 0)
			return -99.99;
		cout << "finsh findAVG inside" << endl;
		return (sum / count);
};

	//find the mode of the ll and return the string of result
	double findMode(std::string location, int upYr, int dwnYr){
		vector<double> nums;
		for (Node* curr = head; curr != nullptr; curr = curr -> next) {
			if((curr -> data.id == location) && (curr -> data.year <= dwnYr) && (curr -> data.year >= upYr))
				nums.push_back(round(curr -> data.temperature));
		}

	    for (int i = 0; i < (nums.size()) - 1; i++) {
			for (int j = 0; j < (nums.size() - 1 - i); j++) {
		    	if (nums[j] > nums[j + 1]) {
				int temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
		    	}
			}
	    }

	    int num;
	    int currFre = 0, maxFre = 0;

		for (int i = 0; i < nums.size(); i++) {
			currFre ++;
			if (nums.at(i) != nums.at(i + 1) || i == (nums.size() - 1)) {
				if (currFre >= maxFre) {
					maxFre = currFre;
					num = nums.at(i);
				}
				currFre = 0;
			}
		}
		if (maxFre == 1)
			return -99.99;
		else
			return num;
	};
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll){
	os << ll.print();
	return os;
};

class TemperatureDatabase {
	public:
		TemperatureDatabase();
		~TemperatureDatabase();

		// The two functions below are required

		// Read the temperature records from the data file and populate the linked list
		// Implement for Part 1
		void loadData(const std::string& data_file){
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
		};
			
		// Output the data as ordered in the linked list (useful for debugging part 1)
		void outputData(const std::string& out_file){
			ofstream dataout("sorted." + filename);
			
			if (!dataout.is_open()) {
				cout << "Error: Unable to open " << filename << endl;
				exit(1);
			}
			dataout << records.print();
		};

		// Read the queries from the query file and perform a series of queries
		// Implement for Part 2
		void performQuery(const std::string& query_filename){
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
					cout << "finish outFS" << endl;
					if(que == "AVG") {
						cout << "go into AVG" << endl;
						double AVG = records.findAVG(id, upYr, dwnYr);
						if (AVG == -99.99)
							outFS << "unknown" << endl;
						else
							outFS << AVG << endl;
					}
					cout << "start MODE" << endl;
					if (que == "MODE") {
						double MODE = records.findMode(id, upYr, dwnYr);
						if (MODE == -99.99)
							outFS << "unknown" << endl;
						else
							outFS << MODE << endl;
					}
					cout << "finish MODE" << endl;
				}
			}

			inFS.close();
			outFS.close();
		};

	private:
		// Linked list to store the temperature records. You need to properly populate
		// this link list.
		LinkedList records;

		// You can add any private member variables/functions you feel useful in this class.
		int curr_year = 2020;
};

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
		TemperatureDatabase database;
		database.loadData(argv[1]);
		//database.outputData(argv[1]); // comment out before submitting Part 2
		database.performQuery(argv[2]); // Will be done in Part 2
	}
	return 0;
}