#include "bite.h"

#include <string>
#include <vector>
#include <iostream>

Bite::Bite(string fileName = "bite.txt") {

    // tokenize the file input
    Tokenizer T;
    vector<vector<string>>tokens = T.tokenize(fileName);
    
    // print tokens
    for (vector<string> v : tokens) { for (string s : v) { cout << " <" << s << "> "; } cout << endl; } cout << endl;
    cout << "::::Tokenization complete" << endl << endl;

    // turn the tokens into program lines
    Programizer P;
    program = P.programize(tokens);

    //program.print();
}


bool Bite::execute() {
    return program.execute();
}

void Bite::print() {
    program.print();
}
