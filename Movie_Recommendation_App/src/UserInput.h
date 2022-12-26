#ifndef USERINPUT_H
#define USERINPUT_H

#include <vector>
#include <string>

using namespace std;

/*
 * Represents data collected from the user.
 * This data will be used to sort a list of
 * movies.
 *
 * All data is initialized to their
 * respective default empty values.
 */

struct UserInput {
	short year = -1;
	short duration = -1;
	float rating = -1;
	vector<string> genres;
	vector<string> countries;
	vector<string> languages;
	vector<string> directors;
	vector<string> writers;
	vector<string> actors;
	void print();
};

#endif
