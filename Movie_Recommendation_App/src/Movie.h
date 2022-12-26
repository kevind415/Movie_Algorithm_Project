#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

using namespace std;

/*
 * Represents data for a movie
 */
struct Movie {
	string title;
	short year = -1;
	string genres;
	short duration = -1;
	string countries;
	string languages;
	string directors;
	string writers;
	string description;
	string actors;
	float rating = -1;
};

#endif
