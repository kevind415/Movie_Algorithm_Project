#include <iostream>

#include "UserInput.h"

using namespace std;

void UserInput::print() {
	cout << "Movie year: ";
	if (year == -1) cout << "(not set)" << endl;
	else
	{
		cout << year << endl;
	}
	cout << "Duration: ";
	if (duration == -1) cout << "(not set)" << endl;
	else
	{
		cout << duration << endl;
	}
	cout << "Rating: ";
	if (rating == -1) cout << "(not set)" << endl;
	else
	{
		cout << rating << endl;
	}
	string delim = "";
	cout << "Genres: ";
	if (genres.size() == 0) cout << "(not set)" << endl;
	else
	{
		for (auto genre : genres) {
			cout << delim << genre;
			delim = ", ";
		}
		delim = "";
		cout << endl;
	}
	cout << "Countries: ";
	if (countries.size() == 0) cout << "(not set)" << endl;
	else
	{
		for (auto country : countries) {
			cout << delim << country;
			delim = ", ";
		}
		delim = "";
		cout << endl;
	}
	
	cout << "Languages: ";
	if (languages.size() == 0) cout << "(not set)" << endl;
	else
	{
		for (auto language : languages) {
			cout << delim << language;
			delim = ", ";
		}
		delim = "";
		cout << endl;
	}

	cout << "Directors: ";
	if (directors.size() == 0) cout << "(not set)" << endl;
	else
	{
		for (auto director : directors) {
			cout << delim << director;
			delim = ", ";
		}
		delim = "";
		cout << endl;
		cout << endl;
	}

	cout << "Writers: ";
	if (writers.size() == 0) cout << "(not set)" << endl;
	else
	{
		for (auto writer : writers) {
			cout << delim << writer;
			delim = ", ";
		}
		delim = "";
		cout << endl;
	}

	cout << "Actors: ";
	if (actors.size() == 0) cout << "(not set)" << endl;
	else
	{
		for (auto actor : actors) {
			cout << delim << actor;
			delim = ", ";
		}
		delim = "";
		cout << endl;
	}
}