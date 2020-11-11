#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
	int val;
	Node* next;

	// Default constructor
	Node() : val(), next(nullptr) {}; // remember to initialize next to nullptr
	Node(int val) : val(val), next(nullptr) {}; // remember to initialize next to nullptr

	// This operator will allow you to just ask if a node is smaller than another
	//  rather than looking at all of the location, temperature and date information
	bool operator<(const Node& b) {
		return this -> val < b.val;
	}

  // The function below is written. Do not modify it
	virtual ~Node() {}
};

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	// Default constructor
	LinkedList() : head(nullptr), tail(nullptr) {}

	// Destructor
	~LinkedList() {
		clear();
	}

	bool is_empty() const
	{
	    if (head == nullptr && tail == nullptr)
	        return true;
	    else
	        return false;
	}

	void insert_front(int value) {
	    Node* newNode = new Node(value);
	    newNode->next = head; // attach to list
	    head = newNode;
	    if (tail == nullptr) { // empty list
	        tail = newNode; // only node is both head and tail
	    }
	}

	void insert_back(int value) {
	    Node* newNode = new Node(value);
	    if (tail != nullptr)
	        tail->next = newNode; // attach to list
	    tail = newNode;
	    if (head == nullptr) { // empty list
	        head = newNode; // only node is both head and tail
	    }
	}

	void insert_after(int after_val, int insert_val) {
	    if (head == nullptr) {
	        return ;
	    }
	    else {
	        Node* curr = head;
	        while (curr != nullptr) {
	            if (curr -> val == after_val) {
	                Node* new_node = new Node(insert_val);
	                new_node -> next = curr -> next;
	                curr -> next = new_node;
	                if (curr == tail) {
	                    tail = new_node;
	                }
	            } else {
	                curr = curr -> next;
	            }
	        }
	    }
	}

	void clear() {
		while (head != nullptr) {
			Node* temp = head -> next;
			delete head;
			head = temp;
		}
	}

	// The functions below are written already. Do not modify them.
	std::string print() const {
		std::stringstream ss;
		Node* curr = head;
		while(curr != nullptr) {
			ss << curr -> val << endl;
			curr = curr -> next;
		}

		return ss.str();
	}

	Node* getHead() const{
	    return head;
	}

	double findAVG(){

		double sum = 0.0;
		int count = 0;
		for (Node* curr = head; curr != nullptr; curr = curr -> next) {
			sum += curr -> val;
			count ++;
		}

		if (count == 0) {
			cout << "Error: empty list..." << endl;
			system("pause");
			exit(1);
		}

		return (sum / count);
	}

	void removeMax() {

		int maxNum = getHead() -> val, count = 1, i;
		vector<int> index;

		for (Node* curr = head; curr != nullptr; curr = curr -> next) {
			if (curr -> val > maxNum) {
				index.clear();
				index.push_back(count);
				maxNum = curr -> val;
			} else if (curr -> val == maxNum) {
				index.push_back(count);
			}
			count ++;
		}

		// cout << "The maxNum is: " << maxNum << endl;
		// cout << "The location is: ";
		// for (int i = 0; i < index.size(); i++) {
		// 	cout << index.at(i) << " ";
		// }
		// cout << "\nTry to rm the maxNum..." << endl;

		// if (index.size() == 0) {
		// 	cout << "There is no maxNum..." << endl;
		// 	system("pause");
		// 	exit(1);
		// }	
		
		count = i = 1;

		for (Node* curr = head; curr != nullptr; curr = curr -> next) {
			if (std::count(index.begin(), index.end(),(count + i))) {
				int j = 1;
				delete curr -> next;
				if (!(std::count(index.begin(), index.end(), (count + i + j)))) {
					curr -> next = curr -> next -> next;
					i++;
				} else {
					Node* curr_repeat = curr -> next -> next;					
					while(std::count(index.begin(), index.end(), (count + i + j))) {
						curr_repeat = curr_repeat -> next;
						j++;
					}
					curr -> next = curr_repeat;
					i += j;
				}
			}
			count ++;
		}

		if (std::count(index.begin(), index.end(),1)) {
			Node* curr = head -> next;
			delete head;
			head = curr;
		}
	}

	void reverse() {
        // Initialize current, previous and 
        // next pointers 
        Node* current = head; 
        Node *prev = NULL, *next = NULL; 
  
        while (current != NULL) { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev;
	}
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
};

int main() {
	LinkedList ll;

	ll.insert_back(27);
	ll.insert_back(27);
	ll.insert_back(18);
	// ll.insert_back(7);	
	// ll.insert_back(15);
	// ll.insert_back(18);	
	ll.insert_back(27);
	ll.insert_back(27);
	ll.insert_back(27);
	ll.insert_back(18);
	ll.insert_back(27);
	// ll.insert_back(18);
	ll.insert_back(27);

	cout << ll << endl << endl;
	ll.removeMax();
	cout << endl << ll;
	// ll.reverse();
	// cout << endl << ll;


	return 0;
}