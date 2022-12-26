#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <string>

using namespace std;

/*
 * A Tokenizer will split a string into multiple tokens,
 * using the delimiter to split, and an escape character
 * to preserve the delimiter and the escape character
 * itself within the token.
 */
class Tokenizer {
public:

	/*
	 * Constructs a Tokenizer, with default ',' delimiter
	 * and '"' escape characters
	 */
	Tokenizer();

	/*
	 * Constructs a Tokenizer with custom delimiter
	 * and escape characters
	 */
	Tokenizer(char delimiter, char escape);

	/*
     * Tokenizes an entire line of comma separated values into
	 * a list of tokens. The token list will have at least
	 * one token in it, even if the line is empty.
	 */
	void Tokenize(const string& line);

	/* returns the count of tokens in the token list */
	unsigned int TokenCount() const;

	/* returns true if the current token is not the last token */
	bool HasTokensRemaining() const;

	/* returns the next token in the tokens list */
	const string& NextToken();

private:

	/* used to split a string into tokens */
	char delimiter;

	/* used to preserve delimiters and itself */
	char escape;

	/* a list of tokens from the most recent tokenized string */
	vector<string> tokens;

	/* the index of the current token */
	unsigned int currentToken;
};

#endif