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
            cout << " <" << s << "> ";
        }
        cout << endl;
    }
    cout << endl;

    // reduce tokens (remove empty lines and comments)
    inputTokens = reduceTokens(inputTokens);

    for (vector<string> v : inputTokens) {
        for (string s : v) {
            cout << " <" << s << "> ";
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



// removes comments and white spaces and comments in the token list
// TODO: change addresses to numbers
vector<vector<string>> Bite::reduceTokens(vector<vector<string>> inputTokens) {

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


// reports any violation of syntax
bool Bite::tokenError(vector<vector<string>> inputTokens) {

    for (vector<string> v : inputTokens) {
        
        // non valid code: return false
        if (codeNum.find(v[0]) == codeNum.end()) {
            cout << "unknown op code: " << v[0] << endl;
            return false;
        }

        // check that all registers and numbers are valid
        for (size_t i = 1; i < v.size(); i++) {
            if (!(isValidReg(v[i]) || isValidNum(v[i]))) {
                cout << "unknown register/number: " << v[i] << endl;
                return false;
            }
        }

        // valid code with valid arguments: continue
        // switch (codeNum[v[0]])
        // {
        // case ADD:   case AND:   case OR:
            
        //     break;
        // case:

        // default:
        //     break;
        // }
        
        
        // for (size_t i = 0; i < v.size(); i++) {

        //     // if the token is blank or the token is a comment
        //     if (v[i].compare("") == 0 || (v[i][0] == '/' && v[i][1] == '/')) {
        //         break;
        //     }

        //     // if it's the first token of the line and it doesnt match an op code
        //     if (i == 0 && codeNum.find(v[i]) == codeNum.end()) {
        //         cout << "ERROR: unknown token " << v[i] << endl;
        //         return false;
        //     } else {
        //         continue;
        //     }

        //     // if it's a register and a valid register
        //     if (v[i][0] == '$' && strtoi(v[i].substr(1)) < sizeof(reg)) {
        //         continue;
        //     }

        //     // if it's a number below 255
        //     if (strtoi(v[i]) < 255) {
        //         continue;
        //     }

        //     return false;
        // }
    }

    return true;
}










bool Bite::isValidReg(string token) {
    if (token[0] == '$' && strtoi(token.substr(1)) < sizeof(reg)) {
       
        return true;
    } else {

         if (token[0] == '$')  
            cout << "dollar sign check" << endl;
        
        cout << "substr: " << token.substr(1) << endl;
        cout << "num check: " << strtoi(token.substr(1)) << endl;
        

        cout << "reg return false" << endl;
        return false;
    }
}

bool Bite::isValidNum(string token) {
    if (strtoi(token) < 255) 
        return true;
    else
        return false;
}









// helps turn strings into integers
size_t strtoi(string s) {

    size_t ret = 0;

    for (auto i = 0; i < s.size(); i++) {

        cout << "character: " <<s [i] << endl;

        ret *= 10;

        // if a character is not a number
        if (s[i] < 48 || s[i] > 57)
            return SIZE_T_MAX;
        else
            ret += s[i] - 48;
   } 

   return ret;
}