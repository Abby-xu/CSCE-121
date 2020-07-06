int getRange(int maxVal, int minVal, string prompt) {
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

void processChoice(int choice) {
	try {
		// volumes are always positive, so initialize to non-valid value
		double r = 0; // radius
		int s; // side
		int h; // height

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
		case 4: // do nothing we are exiting
			break;
		default:
			throw runtime_error("Invalid Choice: " + to_string(choice));
		}
	}
	catch (char c) {
		ostringstream oss;
		oss << "Programming Error: '" << c << "' not implemented.";
		throw runtime_error(oss.str());
	}
}

void printMenu() {
	cout << endl << "Menu" << endl;
	cout << "1: Volume of a sphere" << endl;
	cout << "2: Volume of a cube" << endl;
	cout << "3: Volume of a cylinder" << endl;
	cout << "4: Exit" << endl << endl;
}

