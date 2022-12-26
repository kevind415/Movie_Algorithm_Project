#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "MovieLibrary.h"
#include "UserInput.h"

using namespace std;

const int WIDTH = 50;

void printMenuLine(int number, string option) {
	string line;
	line += "| ";
	line += to_string(number);
	line += ". ";
	line += option;
	cout << left << setw(WIDTH) << line << setfill(' ') << "|" << endl;
}

void updateInput(short& value) {
	short tmp;
	system("CLS");
	cout << "Current value: ";
	if (value != -1) cout << value << endl;
	else cout << "(not set)" << endl;
	cout << "Enter new value: ";
	cin >> tmp;
	value = tmp;
	return;
}

void updateInput(float& value) {
	float tmp;
	system("CLS");
	cout << "Current value: ";
	if (value != -1) cout << value << endl;
	else cout << "(not set)" << endl;
	cout << "Enter new value: ";
	cin >> tmp;
	value = tmp;
	return;
}

void updateInput(vector <string> &v) {
	int choice;
	bool isRunning = true;
	while (isRunning) {
		system("CLS");
		string delim = "";
		string tmp;
		int indx;
		cout << "Current values: ";

		if (v.size() == 0) cout << "(not set)" << endl;
		else
		{
			for (auto value : v) {
				cout << delim << value;
				delim = ", ";
			}
			delim = "";
			cout << endl;
		}
		cout << "+-------------------------------------------------+" << endl;
		cout << "|             Update preference                   |" << endl;
		printMenuLine(0, "Back to previous menu");
		printMenuLine(1, "Remove element from preferences list");
		printMenuLine(2, "Add new element to preferences");
		cout << "+-------------------------------------------------+" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "Going back to previous menu ..." << endl;
			isRunning = false;
			system("CLS");
			break;
		case 1:
			
			for (int i = 0; i < v.size(); i++) {
				cout << i + 1 << ". " << v[i] << endl;
			}
			cout << "Select value to remove";
			cin >> indx;
			if (0 <= indx && indx <= v.size()) {
				v.erase(v.begin() + indx - 1);
			}
			break;
		case 2:
			cout << "Enter new value to add: ";
			cin >> tmp;
			v.push_back(tmp);
			system("CLS");
			break;
		default:
			cout << "Invalid option." << endl;
			break;
		}
	}
}

void inputLoop(UserInput &in, MovieLibrary &library) {
	int choice;
	bool isRunning = true;
	
	in.genres.push_back("Action");
	in.countries.push_back("USA");
	in.countries.push_back("UK");
	in.languages.push_back("English");
	in.rating = 7.0;
	
	while (isRunning) {
		//system("CLS");
		cout << "Your current preference:" << endl;
		in.print();
		cout << "+-------------------------------------------------+" << endl;
		cout << "|             Find movie menu                     |" << endl;
		printMenuLine(0, "Back to previous menu");
		printMenuLine(1, "Find movies with current preferences");
		printMenuLine(2, "Change movie year");
		printMenuLine(3, "Change duration");
		printMenuLine(4, "Change rating");
		printMenuLine(5, "Change genres");
		printMenuLine(6, "Change countries");
		printMenuLine(7, "Change languages");
		printMenuLine(8, "Change directors");
		printMenuLine(9, "Change writers");
		printMenuLine(10, "Change actors");
		cout << "+-------------------------------------------------+" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 0:
			cout << "Going back to previous menu ..." << endl;
			isRunning = false;
			break;
		case 1:
			library.Sort(in);
			library.PrintFirst10MovieTitles();
			break;
		case 2:
			updateInput(in.year);
			system("CLS");
			break;
		case 3:
			updateInput(in.duration);
			system("CLS");
			break;
		case 4:
			updateInput(in.rating);
			system("CLS");
			break;
		case 5:
			updateInput(in.genres);
			break;
		case 6:
			updateInput(in.countries);
			break;
		case 7:
			updateInput(in.languages);
			break;
		case 8:
			updateInput(in.directors);
			break;
		case 9:
			updateInput(in.writers);
			break;
		case 10:
			updateInput(in.actors);
			break;
		default:
			cout << "Invalid option." << endl;
			break;
		}
	}
}
void mainLoop(MovieLibrary& library) {
	int choice;
	bool isRunning = true;
	UserInput in;
	while (isRunning) {
		system("CLS");
		cout << "+-------------------------------------------------+" << endl;
		cout << "|             Movie Recommendation                |" << endl;
		printMenuLine(0, "Exit program");
		printMenuLine(1, "Find a Movie");
		//printMenuLine(2, "See trending/popular movies");
		
		cout << "+-------------------------------------------------+" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 0:
			isRunning = false;
			break;
		case 1:
			cout << "Going to find movie menu..." << endl;
			system("CLS");
			inputLoop(in, library);
			break;
		default:
			cout << "Invalid option." << endl;
			break;
		}
	}
}

// entry point
int main() {
	MovieLibrary library;
	library.LoadLibrary("res/IMDb movies.csv");
	mainLoop(library);
	cout << "Finished without error";
	return 0;
}
