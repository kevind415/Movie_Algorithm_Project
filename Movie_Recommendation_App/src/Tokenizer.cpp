#include <iostream>

#include "Tokenizer.h"

Tokenizer::Tokenizer()
    : delimiter(','), escape('"'), tokens(21), currentToken(0) {
}

Tokenizer::Tokenizer(char delimiter, char escape)
    : delimiter(delimiter), escape(escape), tokens(21), currentToken(0) {
}

void Tokenizer::Tokenize(const string& line) {
    /* Clear the current tokens list */
    tokens.clear();
    currentToken = 0;

    if (line.empty()) {
        /* Add empty tokens quickly */
        tokens.push_back(line);
        return;
    }

    unsigned int length = line.length();
    unsigned int index = 0;

    string token;
    bool esc = false;

    for (; index < length; ++index) {
        char character = line[index];

        if (!esc && character == delimiter) {
            /* Only add the token if we aren't escaping */
            tokens.push_back(token);
            token.clear(); // prepare the next token
        } else if (character != escape) {
            /*
             * All non-escape characters get added
             *
             * NOTE: it is possible for delimiters to get added
             *       here if escape state is enabled
             */
            token += character;
        } else {
            if (esc && index + 1 < length && line[index + 1] != delimiter) {
                /*
                 * Only add escape chars if an escaped token
                 * is ending (escape state toggled to false
                 * and next character is delimiter)
                 */
                token += character;
            }

            /* flip the escape state */
            esc = !esc;
        }
    }

    /*
     * Add the last token since tokens only
     * get added when a non-escaped delimiter
     * is found in the loop
     */
    tokens.push_back(token);
}

unsigned int Tokenizer::TokenCount() const {
    return tokens.size();
}

bool Tokenizer::HasTokensRemaining() const {
    return currentToken < tokens.size();
}

const string& Tokenizer::NextToken() {
    return tokens[currentToken++];
}
