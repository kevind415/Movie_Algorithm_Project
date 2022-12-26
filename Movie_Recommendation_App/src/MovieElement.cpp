#include <vector>

#include "MovieElement.h"

MovieElement::MovieElement()
	: movie(Movie()), weightedSum(0) {
}

MovieElement::MovieElement(const Movie& _movie)
	: movie(_movie), weightedSum(0) {
}

void MovieElement::CalculateWeightedSum(const UserInput& input) {
	// reset sum before calculating
	weightedSum = 0;

	// Using a weight of 5 scales each found element in list
	// by equating to:
	//     weight of 1 year difference
	//     weight of 25 minute difference
	//     weight of 5.0 rating difference
	CalculateWeight(input.genres,    movie.genres,    5.0);
	CalculateWeight(input.countries, movie.countries, 5.0);
	CalculateWeight(input.languages, movie.languages, 5.0);
	CalculateWeight(input.directors, movie.directors, 5.0);
	CalculateWeight(input.writers,   movie.writers,   5.0);
	CalculateWeight(input.actors,    movie.actors,    5.0);

	if (input.year != -1) {
		float deltaYear = movie.year - input.year;
		// carries less weight the larger the difference
		weightedSum -= deltaYear * deltaYear;
	}

	if (input.duration != -1) {
		// every 5 minute difference should quadratically decrease weight
		float deltaDuration = (movie.duration - input.duration) / 5.0f;
		// carries less weight the larger the difference
		weightedSum -= deltaDuration * deltaDuration;
	}

	if (input.rating != -1) {
		float deltaRating = movie.rating - input.rating;

		if (input.rating > movie.rating) {
			// carries less weight if the movie rating
			// is worse than user input
			weightedSum -= deltaRating * deltaRating;
		} else {
			// carries more weight if the movie rating
			// is better than user input
			weightedSum += deltaRating * deltaRating;
		}
	}
}

bool ContainsIgnoreCase(const string& str, const string& search) {
	unsigned int strLength = str.length();
	unsigned int searchLength = search.length();

	if (strLength < searchLength) {
		// fail fast
		return false;
	}

	unsigned int strIndex = 0;
	unsigned int searchIndex = 0;

	for (; strIndex < strLength; ++strIndex) {
		if (tolower(search[searchIndex++]) != tolower(str[strIndex])) {
			// char mismatch - reset search index
			searchIndex = 0;
		}

		if (searchIndex == searchLength) {
			// whole string was found, return true
			return true;
		}
	}

	// end of str, no match
	return false;
}

void MovieElement::CalculateWeight(const vector<string> list, const string& str, float weight) {
	unsigned int size = list.size();

	while (size > 0) {
		if (ContainsIgnoreCase(str, list[--size])) {
			// found, carries more weight
			weightedSum += weight * weight;
		} else {
			// not found, carries less weight
			weightedSum -= weight * weight;
		}
	}
}

bool MovieElement::operator<(const MovieElement& other) {
	return other.weightedSum < weightedSum; // decending order
}


