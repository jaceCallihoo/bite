#include "programizer.h"


#include <iostream>

Program Programizer::programize(vector<vector<string>> tokens) {

    // remove comments
    tokens = removeComments(tokens);
    for (vector<string> v : tokens) { for (string s : v) { cout << " <" << s << "> "; } cout << endl; } cout << endl;
    cout << "::::Removed Comments" << endl;

    tokens = removeGaps(tokens);

    // change all the addresses in the tokens to numbers
    tokens = addressToNum(tokens);
    for (vector<string> v : tokens) { for (string s : v) { cout << " <" << s << "> "; } cout << endl; } cout << endl;
    cout << endl << "::::Adresses changed to numbers" << endl << endl;

    tokens = removeGaps(tokens);

    return tokenToProgram(tokens);
}

vector<vector<string>> Programizer::removeComments(vector<vector<string>> tokens) {

    for (vector<string> &token : tokens) {
        for (size_t i = 0; i < token.size(); i++) {

            if (token[i][0] == '/' && token[i][1] == '/') {
                token.erase(token.begin() + i, token.end());
            }
        }
    }

    return tokens;
}

vector<vector<string>> Programizer::removeGaps(vector<vector<string>> tokens) {

    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i].size() == 0) {
            tokens.erase(tokens.begin() + i);
            i--; // account for the erased line
        }
    }

    return tokens;

}

vector<vector<string>> Programizer::addressToNum(vector<vector<string>> tokens) {

    size_t addressLineCount = 0;

    // itterate through every line of the "file"
    for (size_t fileLine = 0; fileLine < tokens.size(); fileLine++) {

        // for each token in the given line
        for (string token : tokens[fileLine]) {
            
            
            // if its an address
            if (tokens[fileLine][0][tokens[fileLine][0].size() - 1] == ':') 
            {
                cout << "address at: " << fileLine << endl;

                size_t addressLine = fileLine;
                size_t addressNum = fileLine - addressLineCount;
                addressLineCount++;

                // erase the address line
                //tokens.erase(tokens.begin() + fileLine, tokens.end());
                tokens[fileLine].clear();

                // search through all tokens   
                for (size_t fileLine = 0; fileLine < tokens.size(); fileLine++) {
                    for (string &token : tokens[fileLine]) {

                        // if the token matches the address name: change the token to the correct number
                        if (token.compare(tokens[addressLine][0].substr(0, tokens[addressLine][0].size() - 1)) == 0) {
                            cout << "address to number at: " << addressLine << endl;
                            token = to_string(addressNum);
                            cout << "new value: " << token << endl;
                        }
                    }
                }
            }
        }
    }
    return tokens;
}

Program Programizer::tokenToProgram(vector<vector<string>> tokens) {

    Program P;
    BluePrint BP;

    tokens.push_back({"J", "255"});

    for (size_t line = 0; line < tokens.size(); line++) {

        cout << "line num: " << line << endl;

        // map line to blue print
        P.addLine(BP.tokenArrayToLine(tokens[line]));
    }

    for (int i = 0; i < tokens.size(); i++) {
        for (int j = 0; j < tokens[i].size(); j++) {
            cout << tokens[i][j] << " ";
        }
        cout << endl;
    }

    P.addPrintTokens(tokens);

    return P;
}