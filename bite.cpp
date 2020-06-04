#include "bite.h"

#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

// fix me later
#define SIZE_T_MAX 5000

size_t strtoi(string s);


Bite::Bite(string fileName  = "bite.txt") {

    // move the file into an array of strings
    vector<string> inputText = fileToString(fileName);

    for (string s : inputText) {
        cout << s << endl;
    }

    cout << endl;

    // tokenize the input text
    vector<vector<string>> inputTokens = tokenize(inputText);

    for (vector<string> v : inputTokens) {
        for (string s : v) {
            cout << s << " | ";
        }
        cout << endl;
    }
    cout << endl;

    // reduce tokens (remove empty lines and comments)
    inputTokens = reduceTokens(inputTokens);

    for (vector<string> v : inputTokens) {
        for (string s : v) {
            cout << s << " | ";
        }
        cout << endl;
    }
    cout << endl;

    // error check tokens
    bool foo = tokenError(inputTokens);

    if (foo) {
        cout << "no errors" << endl;
    } else {
        cout << "error found" << endl;
    }

    // convert tokens to lines

}

// takes a name of a file and converts it's text into an array of strings
vector<string> Bite::fileToString(string fileName) {
    
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
vector<vector<string>> Bite::tokenize(vector<string> inputText) {

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



// removes comments and white spaces in the token list
vector<vector<string>> Bite::reduceTokens(vector<vector<string>> inputTokens) {

    for (size_t i = 0; i < inputTokens.size(); i++) {
        cout << "token: " << i << endl;

        // if this string is an empty line, remove it
        if (inputTokens[i].size() == 0) {
            cout << "remove line" << endl;
            inputTokens.erase(inputTokens.begin() + i);
        }

        // remove any comments
        for (size_t j = 0; j < inputTokens[i].size(); j++) {
            if (inputTokens[i][j][0] == '/' && inputTokens[i][j][1] == '/') {
                cout << "erase from token: " << j << endl;
                inputTokens[i].erase(inputTokens[i].begin() + j, inputTokens[i].end());
            }
        }
    }

    return inputTokens;
}


//
bool Bite::tokenError(vector<vector<string>> inputTokens) {

    for (vector<string> v : inputTokens) {
        for (size_t i = 0; i < v.size(); i++) {

            // if the token is blank or the token is a comment
            if (v[i].compare("") == 0 || (v[i][0] == '/' && v[i][1] == '/')) {
                break;
            }

            // if it's the first token of the line and it doesnt match an op code
            if (i == 0 && codeNum.find(v[i]) == codeNum.end()) {
                cout << "ERROR: unknown token " << v[i] << endl;
                return false;
            } else {
                continue;
            }

            // if it's a register and a valid register
            if (v[i][0] == '$' && strtoi(v[i].substr(1)) < sizeof(reg)) {
                continue;
            }

            // if it's a number below 255
            if (strtoi(v[i]) < 255) {
                continue;
            }

            return false;
        }
    }

    return true;
}




















// helps turn strings into integers
size_t strtoi(string s) {

    size_t ret = 0;
    size_t mult = 1;

    for (auto i = s.size() - 2; i >= 0; i--, mult *= 10) {

        // if a character is not a number
        if (s[i] < 48 || s[i] > 57)
            return SIZE_T_MAX;
        else
            ret += s[i] * mult;
   } 

   return ret;
}