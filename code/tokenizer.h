#pragma once

#include <vector>
#include <string>

using namespace std;

class Tokenizer
{
private:
    

public:
    vector<vector<string>> tokenize(string fileName);
    vector<string> fileToString(string fileName);
    vector<vector<string>> lineToToken(vector<string> inputText);
    vector<vector<string>> reduceTokens(vector<vector<string>> inputTokens);
    bool tokenError(vector<vector<string>> inputTokens);
    void toLines(vector<vector<string>> inputTokens);
};
