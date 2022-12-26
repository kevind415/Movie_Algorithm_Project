#include <iostream>
#include <fstream>
#include <algorithm>

#include "MovieLibrary.h"

using namespace std;

MovieLibrary::MovieLibrary()
	: movieList() { }

void MovieLibrary::LoadLibrary(const string& path) {
	ifstream file;

	file.open(path);

	if (file.fail()) {
		cout << "Failed to open file from path '" << path << '\'' << endl;
		cout << "Press 'enter' to exit..." << endl;
		cin.get();
		exit(1);
	}

	Tokenizer tokenizer;
	string csvLine;

	cout << "Parsing movie library" << endl;

	// skip the first csv line, its just
	// the format of the csv data
	getline(file, csvLine);
	tokenizer.Tokenize(csvLine);

	while (getline(file, csvLine)) {
		tokenizer.Tokenize(csvLine);
		ParseMovie(tokenizer);
	}

	cout << endl;
	file.close();
}

void MovieLibrary::Sort(const UserInput& input) {
	unsigned int size = max((int) movieList.size(), 10);

	cout << "Calculating weights for " << size << " movies..." << endl;

	while (size > 0) {
		movieList[--size].CalculateWeightedSum(input);
	}

	cout << "Sorting movie list..." << endl;
	sort(movieList.begin(), movieList.end());
}

void MovieLibrary::PrintFirst10MovieTitles() const {
	unsigned int size = min((int) movieList.size(), 10);

	if (size <= 0) {
		cout << "Resulting list is empty!" << endl;
		return;
	}

	unsigned int index;

	for (index = 1; index <= size; ++index) {
		Movie movie = movieList[index - 1].GetMovie();
		cout << "----------------------------------------" << endl;
		cout << index << ". '" << movie.title << '\'' << endl;
		cout << '\t' << "Year:        " << movie.year << endl;
		cout << '\t' << "Rated:       " << movie.rating << endl;
		cout << '\t' << "Actors:      " << movie.actors << endl;
		cout << '\t' << "Directed By: " << movie.directors << endl;
		cout << '\t' << "Written By:  " << movie.writers << endl;
		cout << '\t' << "Countries:   " << movie.countries << endl;
		cout << '\t' << "Languages:   " << movie.languages << endl;
		cout << '\t' << "Genres:      " << movie.genres << endl;
		cout << '\t' << "Duration:    " << movie.duration << " minutes" << endl;
		cout << '\t' << "Description: " << movie.description << endl;
	}
	cout << "----------------------------------------" << endl;
}

void MovieLibrary::ParseMovie(Tokenizer& tokenizer) {
	Movie movie;

	tokenizer.NextToken(); // skip imdb_title_id
	tokenizer.NextToken(); // skip title (unused)
	movie.title = tokenizer.NextToken();

	string year = tokenizer.NextToken();

	if (year.length() == 4) {
		movie.year = stoi(year);
	} else {
		cout << endl << "Error parsing year token '" << year << "' for movie title '" << movie.title << '\'' << endl;
	}

	tokenizer.NextToken(); // skip date
	movie.genres = tokenizer.NextToken();
	movie.duration = stoi(tokenizer.NextToken());
	movie.countries = tokenizer.NextToken();
	movie.languages = tokenizer.NextToken();
	movie.directors = tokenizer.NextToken();
	movie.writers = tokenizer.NextToken();
	tokenizer.NextToken(); // skip production company
	movie.actors = tokenizer.NextToken();
	movie.description = tokenizer.NextToken();
	movie.rating = stof(tokenizer.NextToken());

	// skip the remaining tokens:
	//    budget
	//    usa_gross_income
	//    worlwide_gross_income
	//    metascore
	//    reviews_from_users
	//    reviews_from_critics

	// implicitly calls MovieElement constructor
	movieList.push_back(movie);
}
