#include "tokenizer.h"

#include <iostream>

#include <fstream>
#include <string.h>


vector<vector<string>> Tokenizer::tokenize(string fileName) {

    vector<string> lines = fileToString(fileName);

    // vector<vector<string>> ret = lineToToken(lines);

    return lineToToken(lines);

}

// takes a name of a file and converts it's text into an array of strings
vector<string> Tokenizer::fileToString(string fileName) {
    
    ifstream inputFile;
	inputFile.open(fileName);
	
	string hold;
	vector<string> inputText;					
	for (uint i = 0; getline(inputFile, hold); i++)	
		inputText.push_back(hold);	
	
    inputFile.close();

    return inputText;
}

// takes a vector of strings and returns the text seperated by white space
vector<vector<string>> Tokenizer::lineToToken(vector<string> inputText) {

    vector<vector<string>> ret;

    // tokenize the input
    for (size_t i = 0; i < inputText.size(); i++) {

        ret.push_back(vector<string>());

        // Tokenize input
        for (auto j = strtok(&inputText[i][0], " "); j != NULL; j = strtok(NULL, " "))
            ret[i].push_back(j);

    }
    return ret;
}



// removes comments and white spaces and comments in the token list
// TODO: change addresses to numbers
vector<vector<string>> Tokenizer::reduceTokens(vector<vector<string>> inputTokens) {

    for (size_t line = 0; line < inputTokens.size(); line++) {
        cout << "line: " << line << endl;

        // remove any comments
        for (size_t i = 0; i < inputTokens[line].size(); i++) {
            if (inputTokens[line][i][0] == '/' && inputTokens[line][i][1] == '/') {
                cout << "erase from token: " << i << endl;
                inputTokens[line].erase(inputTokens[line].begin() + i, inputTokens[line].end());
            }
        }

        // if this string is an empty line, remove it
        if (inputTokens[line].size() == 0) {
            cout << "remove line" << endl;
            inputTokens.erase(inputTokens.begin() + line);
            line--;        // set line to account for the removed line
            continue;   // dont check for any more things
        }

        // change address names to numbers
        if (inputTokens[line][0][inputTokens[line][0].size() - 1] == ':') {
            cout << "address at: " << line << endl;

              // search throug all tokens
            for (size_t i = 0; i < inputTokens.size(); i++) {
                for (size_t j = 0; j < inputTokens[i].size(); j++) {
                    // if the token is equal to the name of the address, change it to i
                    if (inputTokens[i][j].compare(inputTokens[line][0].substr(0, inputTokens[line][0].size() - 1)) == 0) {
                        cout << "address to number at: " << i << " " << j << endl;
                        inputTokens[i][j] = to_string(line);
                        cout << "new value: " << inputTokens[i][j] << endl;
                    }
                }
            }

            inputTokens.erase(inputTokens.begin() + line);
            line--;        // set line to account for the removed line
            continue;   // dont check for any more things
        }
    }

    return inputTokens;
}
