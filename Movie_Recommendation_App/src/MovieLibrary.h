#ifndef MOVIELIBRARY_H
#define MOVIELIBRARY_H

#include "MovieElement.h"
#include "Tokenizer.h"
#include "UserInput.h"

using namespace std;

/*
 * A MovieLibrary manages a list of MovieElements.
 * The library can parse a CSV file into the movie
 * list internally, which can be sorted by user input.
 */
class MovieLibrary {
public:
	/* Constructs a new MovieLibrary */
	MovieLibrary();

	/*
	 * Loads the movie library by parsing a CSV file
	 * from the provided path. The parsed movies will
	 * populate the movie list.
	 */
	void LoadLibrary(const string& path);

	/*
	 * Sorts the movie list using data from user input
	 * to calculate weighted sums for each movie in the
	 * list.
	 *
	 * After weights are calculated, the movie list will
	 * be sorted in decending order based on their weight.
	 */
	void Sort(const UserInput& input);

	/* Prints the first 10 movies from the movie list */
	void PrintFirst10MovieTitles() const;

private:
	/*
	 * A helper function to aid the LoadLibrary method by
	 * adding a movie to the movies list  from the  given
	 * tokenizer. The tokenizer is assumed to hold tokens
	 * which can be parsed into a movie object.
	 */
	void ParseMovie(Tokenizer& tokenizer);

private:
	/* A list of MovieElement objects*/
	vector<MovieElement> movieList;
};

#endif
