#ifndef MOVIEELEMENT_H
#define MOVIEELEMENT_H

#include <string>

#include "Movie.h"
#include "UserInput.h"

using namespace std;

/*
 * A MovieElement is a wrapper class to add
 * functionality to a Movie object.
 */
class MovieElement {
public:
	/* Constructs a default MovieElement with
	 * an empty movie
	 */
	MovieElement();

	/* Constructs a MovieElement for a Movie*/
	MovieElement(const Movie& movie);

	/* Compares in decending order */
	bool operator<(const MovieElement& other);

	/* Gets the actual movie object */
	const Movie& GetMovie() const {
		return movie;
	}

	/*
	 * Calculates the weighted sum for the movie.
	 * Each field from the movie will be compared
	 * to user input and sets the weightedSum
	 * field. More weight will sort higher in the
	 * movie list
	 */
	void CalculateWeightedSum(const UserInput& input);

private:
	/*
	 * A helper function to calculate weight for a list of strings.
	 *
	 * If the search term is found in the list, the given weight
	 * is added to the weighted sum field.
	 *
	 * Otherwise, weight will be subtracted.
	 */
	void CalculateWeight(const vector<string> list, const string& searchFor, float weight);

private:
	/* the actual movie object */
	Movie movie;

	/* the weight sum of the movie */
	float weightedSum;
};

#endif